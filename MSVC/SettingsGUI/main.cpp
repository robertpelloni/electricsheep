#include "main.h"
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include "electricsheepguiMyDialog2.h"

#ifdef LINUX_GNU
#include "../../Runtime/sheep_logo.xpm"
#endif

enum
{
    ID_TRAY_DASHBOARD = wxID_HIGHEST + 100,
    ID_TRAY_RUN_SCREENSAVER,
    ID_TRAY_KILL_SHEEP,
    ID_TRAY_EXIT
};

wxBEGIN_EVENT_TABLE(ESTrayIcon, wxTaskBarIcon)
    EVT_MENU(ID_TRAY_DASHBOARD, ESTrayIcon::OnOpenDashboard)
    EVT_MENU(ID_TRAY_RUN_SCREENSAVER, ESTrayIcon::OnRunScreensaver)
    EVT_MENU(ID_TRAY_KILL_SHEEP, ESTrayIcon::OnKillSheep)
    EVT_MENU(ID_TRAY_EXIT, ESTrayIcon::OnExit)
    EVT_TASKBAR_LEFT_DCLICK(ESTrayIcon::OnLeftDoubleClick)
wxEND_EVENT_TABLE()

ESTrayIcon::ESTrayIcon(wxWidgetsApp* app)
    : m_app(app)
{
}

ESTrayIcon::~ESTrayIcon()
{
}

wxMenu* ESTrayIcon::CreatePopupMenu()
{
    wxMenu* menu = new wxMenu();
    menu->Append(ID_TRAY_DASHBOARD, wxT("Open Control Dashboard"));
    menu->Append(ID_TRAY_RUN_SCREENSAVER, wxT("▶ Run Screensaver"));
    menu->AppendSeparator();
    menu->Append(ID_TRAY_KILL_SHEEP, wxT("⏹ Stop/Quit Sheep Processes"));
    menu->AppendSeparator();
    menu->Append(ID_TRAY_EXIT, wxT("E&xit Manager"));
    return menu;
}

void ESTrayIcon::OnOpenDashboard(wxCommandEvent& WXUNUSED(event))
{
    if (m_app)
        m_app->ShowDashboard();
}

void ESTrayIcon::OnRunScreensaver(wxCommandEvent& WXUNUSED(event))
{
    if (m_app)
        m_app->RunScreensaver();
}

void ESTrayIcon::OnKillSheep(wxCommandEvent& WXUNUSED(event))
{
    if (m_app)
        m_app->KillSheepServers();
}

void ESTrayIcon::OnExit(wxCommandEvent& WXUNUSED(event))
{
    if (m_app)
        m_app->QuitApplication();
}

void ESTrayIcon::OnLeftDoubleClick(wxTaskBarIconEvent& WXUNUSED(event))
{
    if (m_app)
        m_app->ShowDashboard();
}

// =========================================================================
// wxWidgetsApp Implementation
// =========================================================================

IMPLEMENT_APP(wxWidgetsApp)

wxWidgetsApp::wxWidgetsApp()
    : m_dialog(NULL), m_trayIcon(NULL)
{
}

wxWidgetsApp::~wxWidgetsApp()
{
}

bool wxWidgetsApp::OnInit()
{
    m_dialog = new electricsheepguiMyDialog2((wxWindow*)NULL);

#ifdef WIN32
    wxIcon myicon = wxIcon(L"0");
    m_dialog->SetIcon(myicon);
#endif
#ifdef LINUX_GNU
    wxIcon myicon = wxIcon(eslogo);
    m_dialog->SetIcon(myicon);
#endif

    // Initialize System Tray Icon if platform supports it
    if (wxTaskBarIcon::IsAvailable())
    {
        m_trayIcon = new ESTrayIcon(this);
#ifdef LINUX_GNU
        m_trayIcon->SetIcon(wxIcon(eslogo), wxT("Electric Sheep Control Manager"));
#endif
#ifdef WIN32
        m_trayIcon->SetIcon(wxIcon(L"0"), wxT("Electric Sheep Control Manager"));
#endif
    }

    m_dialog->Centre();
    m_dialog->Show(true);
    SetTopWindow(m_dialog);
    return true;
}

int wxWidgetsApp::OnExit()
{
    if (m_trayIcon)
    {
        m_trayIcon->RemoveIcon();
        delete m_trayIcon;
        m_trayIcon = NULL;
    }
    return wxApp::OnExit();
}

void wxWidgetsApp::ShowDashboard()
{
    if (m_dialog)
    {
        m_dialog->Show(true);
        m_dialog->Raise();
        m_dialog->SetFocus();
    }
}

void wxWidgetsApp::RunScreensaver()
{
#ifndef LINUX_GNU
    wxString windir;
    wxGetEnv(L"WINDIR", &windir);
    wxExecute(windir + L"\\es.scr -x");
#else
    wxExecute(wxT("electricsheep"));
#endif
}

void wxWidgetsApp::KillSheepServers()
{
#ifndef LINUX_GNU
    wxExecute(wxT("taskkill /F /IM electricsheep.exe /T"));
#else
    wxExecute(wxT("pkill -9 electricsheep"));
#endif
    wxMessageBox(wxT("Signal sent to stop and terminate any running Electric Sheep instances."), wxT("Electric Sheep Server Control"), wxICON_INFORMATION);
}

void wxWidgetsApp::QuitApplication()
{
    if (m_dialog)
    {
        m_dialog->Close(true);
    }
    ExitMainLoop();
}
