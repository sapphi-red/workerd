// Copyright (c) 2017-2022 Cloudflare, Inc.
// Licensed under the Apache 2.0 license found in the LICENSE file or at:
//     https://opensource.org/licenses/Apache-2.0

#pragma once

#include <workerd/jsg/jsg.h>
#include <workerd/jsg/modules.h>

namespace workerd::api {

class UnsafeModule final: public jsg::Object {
public:
  jsg::JsValue runInEvalAllowedContext(jsg::Lock& js, jsg::Function<jsg::JsValue()> callback) {
    js.setAllowEval(true);
    auto result = callback(js);
    js.setAllowEval(false);
    return result;
  }

  JSG_RESOURCE_TYPE(UnsafeModule) {
    JSG_METHOD(runInEvalAllowedContext);
  }
};

template <class Registry>
void registerUnsafeModule(Registry& registry) {
  registry.template addBuiltinModule<UnsafeModule>("workerd:unsafe",
    workerd::jsg::ModuleRegistry::Type::BUILTIN);
}

#define EW_UNSAFE_ISOLATE_TYPES api::UnsafeModule

}  // namespace workerd::api
