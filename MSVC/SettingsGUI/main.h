#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>
#include "electricsheepguiMyDialog2.h"

class ESTrayIcon : public wxTaskBarIcon
{
public:
    ESTrayIcon(class wxWidgetsApp* app);
    virtual ~ESTrayIcon();
    virtual wxMenu* CreatePopupMenu() wxOVERRIDE;

    void OnOpenDashboard(wxCommandEvent& event);
    void OnRunScreensaver(wxCommandEvent& event);
    void OnKillSheep(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnLeftDoubleClick(wxTaskBarIconEvent& event);

private:
    class wxWidgetsApp* m_app;
    wxDECLARE_EVENT_TABLE();
};

class wxWidgetsApp : public wxApp
{
public:
    wxWidgetsApp();
    virtual ~wxWidgetsApp();
    virtual bool OnInit();
    virtual int OnExit();

    void ShowDashboard();
    void RunScreensaver();
    void KillSheepServers();
    void QuitApplication();

private:
    electricsheepguiMyDialog2 *m_dialog;
    ESTrayIcon *m_trayIcon;
};

DECLARE_APP(wxWidgetsApp)
