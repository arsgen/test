#ifndef __BROWSER_HANDLER_H__
#define __BROWSER_HANDLER_H__

#include "include/cef_client.h"
#include "include/cef_request_handler.h"

class BrowserHandler : public CefClient, public CefContextMenuHandler, public CefRequestHandler {
 public:
  // Provide access to the single global instance of this object.
  static BrowserHandler* GetInstance();

  virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() {
    return this;
  }

  virtual void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
                                   CefRefPtr<CefFrame> frame,
                                   CefRefPtr<CefContextMenuParams> params,
                                   CefRefPtr<CefMenuModel> model) {
      // disable context menu;
      model->Clear();
  }

  virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message );



  virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE {
      return this;
  }

  virtual CefRefPtr<CefResourceHandler> GetResourceHandler(
      CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame,
      CefRefPtr<CefRequest> request) OVERRIDE;


 private:
  // Include the default reference counting implementation.
  BrowserHandler() {}

  IMPLEMENT_REFCOUNTING(BrowserHandler);
};

#endif
