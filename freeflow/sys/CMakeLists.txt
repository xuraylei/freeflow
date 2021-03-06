# Copyright (c) 2013-2014 Flowgrammable.org
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an "AS IS"
# BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
# or implied. See the License for the specific language governing
# permissions and limitations under the License.

set(src fd_utils.cpp
        meta.cpp
        data.cpp
        error.cpp
        path.cpp
        resource.cpp
        file.cpp
        socket.cpp
        buffer.cpp
        signal.cpp
        time.cpp
        selector.cpp
        syslog.cpp
        pipe.cpp)

if(BSD)
  LIST(APPEND src kqueue.cpp)
elseif(LINUX)
  LIST(APPEND src epoll.cpp)
endif()

# TODO: We need to install all of the .ipp files also.
set(hdr fd_utils.hpp
        meta.hpp
        data.hpp
        error.hpp
        path.hpp
        resoource.hpp
        file.hpp
        socket.hpp
        buffer.hpp
        signal.hpp
        time.hpp
        selector.hpp
        syslog.hpp
        pipe.hpp)

if(BSD)
  LIST(APPEND hdr ${kqueue.hpp})
elseif(LINUX)
  LIST(APPEND hdr ${epoll.hpp})
endif()

add_library(freeflow ${src})


# --------------------------------------------------------------------------- //
# Installation

install(FILES ${hdr} DESTINATION include/freeflow/sys)


# --------------------------------------------------------------------------- //
# Examples
add_subdirectory(examples)


# --------------------------------------------------------------------------- //
# Testing
add_subdirectory(data.test)
add_subdirectory(socket.test)

