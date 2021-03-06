/*
 * Copyright 2010 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// Author: jmaessen@google.com (Jan Maessen)

#include "net/instaweb/util/public/rolling_hash.h"

#include <cstddef>
#include "base/logging.h"
#include "net/instaweb/util/public/basictypes.h"

namespace net_instaweb {

uint64 RollingHash(const char* buf, size_t start, size_t n) {
  CHECK_LE(static_cast<size_t>(0), start);
  buf += start;
  uint64 hash = 0;
  for (size_t i = 0; i < n; ++i) {
    hash = (hash << 1) | (hash >> 63);  // Rotate left 1
    hash ^= kRollingHashCharTable[static_cast<uint8>(buf[i])];
  }
  return hash;
}

const uint64 kRollingHashCharTable[256] = {
    0xf0dcd27e0762b251ULL,
    0xb621e668da0b3d53ULL,
    0xce8c72d316e9293cULL,
    0xe958017c3359bad5ULL,
    0x6b11ca3935e9bb14ULL,
    0x64f67431b8b0bcb4ULL,
    0x8c4dd71ad988d23eULL,
    0x24936d1c08aff78dULL,
    0x69ecc7f3052e0396ULL,
    0xcdc8f08d999754c5ULL,
    0x39ab6e32568685cdULL,
    0x4e4f289b8b96e626ULL,
    0xa3c3cb4a32546b3dULL,
    0xe929810fec372e4dULL,
    0xfd94f0e82a05ac37ULL,
    0x3b71322f12f04f66ULL,
    0x8ad767cc6b92f018ULL,
    0xb4fff19004481ff1ULL,
    0xc9a1422e55e9d8bbULL,
    0x016fccc64de16d17ULL,
    0xd27154733cd80e3eULL,
    0x3f837bd6c3588413ULL,
    0x2c493e9f8c70ee0eULL,
    0xb45526d0cdcae876ULL,
    0xfa8778e134e91383ULL,
    0x0e8f821f8c783f69ULL,
    0xc28fd9493d9268e9ULL,
    0xf5b90b302376dc19ULL,
    0x12d5edf71944c0b9ULL,
    0x3de65234604d9f95ULL,
    0x6e0b7823a5ab650fULL,
    0xf30d1b84d74f542cULL,
    0xd59ea7a1a04daa1eULL,
    0xc322bb145da0eaeeULL,
    0x9f55e20e76bc821cULL,
    0x84eb8f72c858db2cULL,
    0x0727b30ff9b3080fULL,
    0x40cb8bf1f3e4114fULL,
    0x379d10f1f0166fc2ULL,
    0x8766af09de794470ULL,
    0x4cebe022f58b47f0ULL,
    0x75d232d0c4a94ebbULL,
    0xc63ba1fbd098199cULL,
    0xa0d947c29f383a9eULL,
    0x3bfd354a0404e6deULL,
    0x9d3164f90bd471a3ULL,
    0x357f031c2b1cee0eULL,
    0x47bb2d71880becd1ULL,
    0xc048dc946fd9dd85ULL,
    0xa21e8226ed9b2db9ULL,
    0xad06169fbe3a05a9ULL,
    0x0a7b91d58f44e29bULL,
    0x36bdd30c057a61baULL,
    0xcb78135eb2c3b107ULL,
    0xa65907ee1f4209ddULL,
    0x0962bb3ccf9816f2ULL,
    0xceb546dda951601eULL,
    0x5e5769344a1f8f21ULL,
    0x1fe188e97a0685eeULL,
    0x59d0d4289c5edacbULL,
    0xaa212857bb62f723ULL,
    0xa527e223de884eceULL,
    0x9c9a15c9aa56eba4ULL,
    0x9b16d95901aee267ULL,
    0xf4c5b630931f11e9ULL,
    0x3df802e7e85a6750ULL,
    0x4968f654cce17653ULL,
    0xfc3bc0ad02761567ULL,
    0xff18ec7e401c445dULL,
    0x2f844385f9c31b7aULL,
    0x88d750f43c6989edULL,
    0x4bb020be66f231f9ULL,
    0x12502d671fa7f487ULL,
    0x1926420bae67fb5aULL,
    0x2acb699d19d6c4d4ULL,
    0x5cdb79d0349158eaULL,
    0x67e93d1bf4815342ULL,
    0x43dc874f7024e36dULL,
    0xb92097281fed49b6ULL,
    0x62ed4f7a0a6958a9ULL,
    0x574c6b02ae6f3626ULL,
    0xd49b443e8932f23dULL,
    0x7dc50d1a701aab7aULL,
    0x48621174dff0fd92ULL,
    0x5746557ae580c35eULL,
    0x4bc7f97a8ebc2480ULL,
    0x07e620aad2f7b646ULL,
    0x1285636d57e3f612ULL,
    0x9f6cd306e5514c5cULL,
    0x0de00632f6f709d7ULL,
    0x7aa301698adee68bULL,
    0x2df10184f4cfd4ecULL,
    0x5f5b744cf78e8048ULL,
    0x88ebe0a2615fe4b3ULL,
    0xcb6f29a29401f98fULL,
    0x9c306f274e66d287ULL,
    0x88f632944f2ccdd9ULL,
    0x63bcf4a925db4311ULL,
    0xc6d2f5e9c0a50b72ULL,
    0xd6a731846a17be49ULL,
    0x2fd613caa70c235eULL,
    0x534de67031253facULL,
    0x4c685e47e9592796ULL,
    0x9b153e27865bd258ULL,
    0xd614462b61589f7dULL,
    0x1532cb94e28d8cbfULL,
    0x91497f579632a631ULL,
    0x26e3a246cc96fb61ULL,
    0xb28d962661bf129bULL,
    0x85da5d60a6ae5aa3ULL,
    0x0a9a1f6cb7c3e6a0ULL,
    0xae039586bd8c7f11ULL,
    0x0bfd1a8454e77964ULL,
    0xd6fa6b85a423d107ULL,
    0x015c3ab5134f69fcULL,
    0xdab1025b8bed7c18ULL,
    0xdf404b3edca12395ULL,
    0xad3d2d77444e1887ULL,
    0x92654b67bda1e990ULL,
    0xc412fe06d4e29f1eULL,
    0x2d382f434b99af46ULL,
    0x8cb666ada86575a1ULL,
    0x833d4b153f5f5405ULL,
    0x6007f6c51629e797ULL,
    0xd8a1f922cba896e3ULL,
    0x2c9b5a1a249f9e47ULL,
    0xd899781c79cb063bULL,
    0x911f5c7513ea3c91ULL,
    0x0c77ae198ca79978ULL,
    0x20ba7b1e0c97d74cULL,
    0xb3711eccdd549521ULL,
    0x0a94dc19e59543dfULL,
    0x3b348e9c6b0e36a6ULL,
    0x9627b15951a7a6b8ULL,
    0x9193dc839dbe7049ULL,
    0xba707aa6a2add40eULL,
    0x1777251ac57b2a2aULL,
    0xca6c2edba50c4c4fULL,
    0xa6c43cd31526ff60ULL,
    0x310d05dff737a640ULL,
    0xa8663ab4709bdd52ULL,
    0xd05f9d24885f3b94ULL,
    0x8c863ea5aafb221dULL,
    0x21ef263381f8cd63ULL,
    0x4b6fb4a8bc5458aaULL,
    0xc1d84b559be971b0ULL,
    0x210fb1bab7f15072ULL,
    0xe66ee09a51a55963ULL,
    0x39c21db635c08debULL,
    0xf05b979841675d0dULL,
    0x2978a9f732d96470ULL,
    0x4dce978a19c3a1f1ULL,
    0x5c0e92ab7319cd99ULL,
    0x743b286678d9e686ULL,
    0xdaf46993e90a5e81ULL,
    0x96dc2e0adcbb0d16ULL,
    0xd95690fe868663d8ULL,
    0x66ef0231433f2b39ULL,
    0x30774974792d96ccULL,
    0x44ffb0e25c47c44eULL,
    0x4cd9b89be5889713ULL,
    0xe62e5a6014f07cf3ULL,
    0xb56ac85a8af4dea0ULL,
    0xde92b05ba2e1b34aULL,
    0x23fd1311f823b78cULL,
    0xff80ac0f287ec43cULL,
    0x5d90a3866dd95fc0ULL,
    0xdec51083823f593fULL,
    0x86ad4349ac174faeULL,
    0xaedff28454b16a41ULL,
    0x3d8bc08e3f2e0c9dULL,
    0xf86319f232a3c729ULL,
    0xcd5e5e0f94263499ULL,
    0x8d7ba52980b19b79ULL,
    0xa67e8a3d335c81d2ULL,
    0x65d09ac6aa0fdab2ULL,
    0xc1795b7f5b644a20ULL,
    0xec83e7447c32d0dcULL,
    0x6f90245af445f4aeULL,
    0x56d70cadcc4a28fcULL,
    0xaf264eb82bcc4f90ULL,
    0xa16010fce3634affULL,
    0x8ea336b9c2c1e45bULL,
    0x7680ddb84af244bbULL,
    0xf97371315d450666ULL,
    0x8166dfa721896adcULL,
    0x3648e8d5b8d995d8ULL,
    0xa63975a605b31cf2ULL,
    0x35e60de4a3359ad4ULL,
    0x9b81705b2e4be07bULL,
    0xb9ae701a8eb85593ULL,
    0xaedecc0d138f3115ULL,
    0x8a1fdbb92e3423c1ULL,
    0xb0c96dee77615860ULL,
    0x629b7c06bf44e634ULL,
    0x696eb82aa746b1e1ULL,
    0x02efce1165256d4fULL,
    0x69d7a6b7150117a6ULL,
    0x9dcc2d6e896e5681ULL,
    0xcd815845d154cfbeULL,
    0x28ea53acb6da26f0ULL,
    0x7100bc4d21fe52dfULL,
    0x653e558ec969142fULL,
    0x83d730de45a0f5d4ULL,
    0x3831dd5c5647e4b1ULL,
    0x0f4072bf5123e9d5ULL,
    0xa642dce46ec285eeULL,
    0xae995373b5193c28ULL,
    0xf0f3dafb8a611288ULL,
    0xbc482a9e9b15c5abULL,
    0x41668ebcdc7cc0f4ULL,
    0xcdaaef0cd5519603ULL,
    0xebc0b08ad6d7c0e5ULL,
    0xb35073399de97c08ULL,
    0x97e4241d5f265b52ULL,
    0x2e52578c54e99676ULL,
    0x288a75c28fad917bULL,
    0x466e1dd37d710926ULL,
    0x25fd42c4845ce5fcULL,
    0xe0a1137fa3234b76ULL,
    0xfbfc21548eb90370ULL,
    0x8c4cf202e1e875feULL,
    0x9b7cd1e8a5aaa1a1ULL,
    0x2dec3dc9615ca561ULL,
    0xb4458b07977eea11ULL,
    0x75cea1e7a8560366ULL,
    0x109bf4b3b2e39a46ULL,
    0xdf8ed90441ba266bULL,
    0xd1856901e5f8bac7ULL,
    0x7a8b4ab2edd81a62ULL,
    0xb1ae8556c90ae5cbULL,
    0x42d15186c967771fULL,
    0xa07cdf5a38a872a9ULL,
    0x986954db9832acebULL,
    0xf130e68aa4fce616ULL,
    0xcc0caef3d0c76c52ULL,
    0x2c6a3fe49a7d500eULL,
    0x076cb3ad48ed1b85ULL,
    0xe6f8d0aecbb14027ULL,
    0x2cbe5b65d4e5c490ULL,
    0x9dac9ec2da0d12a7ULL,
    0x14ab4abbd07e5ab0ULL,
    0xae99ca6cb4cd1e03ULL,
    0x3bcd346450954fbaULL,
    0x2430fee89dd27a62ULL,
    0x7dc551166f0c94f8ULL,
    0x87947cbebe2a5031ULL,
    0x67003a8dfe2fd1b0ULL,
    0xfed080735857b507ULL,
    0x5097a42c664d9bf9ULL,
    0x9389590f671cf117ULL,
    0x9c5781b4f071956dULL,
    0x9c16eac9bd72017aULL,
    0x45186d635717d743ULL,
    0x3f375208bc7ce161ULL,
    0x768cd5d30f885c47ULL };
}  // net_instaweb
