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

inline void
Selector::add_reader(int fd) { readers.insert(fd); }

inline void
Selector::add_writer(int fd) { writers.insert(fd); }

inline void
Selector::remove_reader(int fd) { readers.remove(fd); }

inline void
Selector::remove_writer(int fd) { writers.remove(fd); }

inline bool
Selector::is_readable(int fd) const { return readers.test(fd); }

inline bool
Selector::is_writable(int fd) const { return writers.test(fd); }

inline int
Selector::operator()() {
  int m = std::max(readers.max, writers.max) + 1;
  int r = ::pselect(m, &readers.fds, &writers.fds, nullptr, nullptr, nullptr);
  if(r == -1 and errno != EINTR)
    throw system_error();
  return r;
}

// TODO: pselect will update the timespec based on the amount of time
// elapsed. It would be nice to return this to the user, but I'm not
// sure what the right interface should be. Maybe this should
// return pair<int, Microseconds>.
inline int
Selector::operator()(Microseconds us) {
  // TODO: Factor this into the time module.
  timespec ts;
  ts.tv_sec = std::chrono::duration_cast<Seconds>(us).count();
  ts.tv_nsec = 1000 * (us.count() % 1000000);

  int m = std::max(readers.max, writers.max) + 1;
  int r = ::pselect(m, &readers.fds, &writers.fds, nullptr, &ts, nullptr);
  if(r == -1 and errno != EINTR)
    throw system_error();

  return r;
}

} // namespace freeflow
