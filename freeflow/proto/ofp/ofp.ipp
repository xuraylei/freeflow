// Copyright (c) 2013-2014 Flowgrammable.org
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an "AS IS"
// BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing
// permissions and limitations under the License.

namespace freeflow {
namespace ofp {

inline Error
to_view(View& v, Uint8 n) {
  put(v, n);
  return {};
}

inline Error
to_view(View& v, Uint16 n) {
  put(v, Byte_order::msbf(n));
  return {};
}

inline Error
to_view(View& v, Uint32 n) {
  put(v, Byte_order::msbf(n));
  return {};
}

inline Error
to_view(View& v, Uint64 n) {
  put(v, Byte_order::msbf(n));
  return {};
}

template<typename T, typename X>
  inline Error
  to_view(View& v, T value) {
    put(Byte_order::msbf(value));
    return {};
  }


inline Error
from_view(View& v, Uint8& n) {
  put(v, n);
  return {};
}

inline Error
from_view(View& v, Uint16& n) {
  put(v, Byte_order::msbf(n));
  return {};
}

inline Error
from_view(View& v, Uint32& n) {
  put(v, Byte_order::msbf(n));
  return {};
}

inline Error
from_view(View& v, Uint64& n) {
  put(v, Byte_order::msbf(n));
  return {};
}

template<typename T, typename X>
  inline Error
  from_view(View& v, T& value) {
    put(Byte_order::msbf(value));
    return {};
  }

} // namespace ofp
} // namespace freeflow