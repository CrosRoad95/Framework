/*
 * MafiaHub OSS license
 * Copyright (c) 2021-2024, MafiaHub. All rights reserved.
 *
 * This file comes from MafiaHub, hosted at https://github.com/MafiaHub/Framework.
 * See LICENSE file in the source repository for information regarding licensing.
 */

#pragma once

#include "include/cef_app.h"
#include "include/cef_browser_process_handler.h"
#include "include/cef_render_process_handler.h"

#include "renderer_app.h"

namespace Framework::GUI::CEF {
    class App final: public CefApp, public CefBrowserProcessHandler, public CefRenderProcessHandler {
      private:
        bool _contextInitialized = false;

      public:
        CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
            return this;
        }

        CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override {
            return this;
        }

        void OnBeforeCommandLineProcessing(const CefString &processType, CefRefPtr<CefCommandLine> commandLine) override;
        void OnContextInitialized() override;
        void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) override;

        bool IsContextInitialized() const {
            return _contextInitialized;
        }

        IMPLEMENT_REFCOUNTING(App);
    };
} // namespace Framework::GUI::CEF
