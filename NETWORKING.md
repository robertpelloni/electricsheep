# Networking Architecture in Electric Sheep

## Overview

Electric Sheep relies on the `Networking` namespace to handle all internal API communications and payload retrieval (downloading sheep, generating uploads, submitting votes). The networking stack is built around `libcurl`, utilizing the `curl_multi_perform` interface to ensure that network I/O operations do not block the main rendering thread.

## Modernization (Phase 3)

### The Concurrency Problem
Previously, while `curl_multi_perform` allowed for pseudo-asynchronous multi-handle connections, individual curl transfers lacked explicit termination parameters. When sheep payloads were fetched from unresponsive nodes or the master tracker went down, the non-blocking `select()` loop inside `CCurlTransfer::InterruptiblePerform()` could theoretically loop indefinitely waiting for a socket event that would never arrive, eventually causing thread starvation.

### Timeout Definitions
To resolve network hangs and guarantee robustness across flaky internet connections, the core transfer definitions in `CCurlTransfer::Perform` have been appended with explicit timeout caps:

```cpp
// Allow the connection to timeout after 10 seconds of no initial response
curl_easy_setopt(m_pCurl, CURLOPT_CONNECTTIMEOUT, 10L);

// Force the overall download transfer to timeout after 30 seconds of inactivity
curl_easy_setopt(m_pCurl, CURLOPT_TIMEOUT, 30L);
```

### Threading & Concurrency Flow

The current design utilizes `boost::thread` mapped over `CURLM*` contexts.
- The `CManager` handles all singleton setup.
- The `Shepherd` class maintains worker thread pools for background operations.
- `CCurlTransfer::InterruptiblePerform` maintains the `select()` wrapper for tracking descriptor readiness, intercepting abort signals cleanly, and releasing the lock back to Boost scheduling.

No major rewrite to Boost.Asio was performed as the native `libcurl` multi-interface already implements sufficient async tracking when configured with proper timeouts.
