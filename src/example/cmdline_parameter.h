/*
 ============================================================================
 * Name        : cmdline_parameter.h
 * Author      : weizhenwei, <weizhenwei1988@gmail.com>
 * Date        : 2016.10.04
 *
 * Copyright (c) 2016, weizhenwei
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the {organization} nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Description : header of cmdline parameter operation.
 ============================================================================
 */

#ifndef SRC_EXAMPLE_CMDLINE_PARAMETER_H
#define SRC_EXAMPLE_CMDLINE_PARAMETER_H

#include <string>

namespace openrtp {

class CmdlineParameter {
public:
    CmdlineParameter();
    ~CmdlineParameter();

    static CmdlineParameter* singleton();
    void parseCmdlineParameter(int argc, char *argv[]);
    void showHelp();
    void showVersion();
    void daemonize();
    inline bool isValidParameter() {return m_bValidParameter;}
    inline bool isShowHelp() {return m_bShowHelp;}
    inline bool isShowVersion() {return m_bShowVersion;}
    inline bool isDaemonize() {return m_bDaemonize;}

private:
    bool m_bValidParameter;
    bool m_bShowHelp;
    bool m_bShowVersion;
    bool m_bDaemonize;
    std::string *m_sProgramName;
    std::string *m_sPidFile;
    std::string *m_sCfgFile;

    static CmdlineParameter *s_pCmdlineParameter;
};

}  // namespace openrtp

#endif  // SRC_EXAMPLE_CMDLINE_PARAMETER_H
