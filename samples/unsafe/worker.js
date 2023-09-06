// Copyright (c) 2017-2023 Cloudflare, Inc.
// Licensed under the Apache 2.0 license found in the LICENSE file or at:
//     https://opensource.org/licenses/Apache-2.0

import unsafe from 'workerd:unsafe'

export default {
  async fetch(req, env) {
    let caught = false;
    try {
      eval('"foo"');
    } catch {
      caught = true;
    }

    const value = unsafe.runInEvalAllowedContext(() => eval('"foo"'));
    return new Response(`caught: ${caught}\nin context: ${value}\n`);
  }
};
