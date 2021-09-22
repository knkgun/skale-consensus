/*
    Copyright (C) 2018-2019 SKALE Labs

    This file is part of skale-consensus.

    skale-consensus is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    skale-consensus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with skale-consensus.  If not, see <https://www.gnu.org/licenses/>.

    @file OracleRequestBroadcastMessage.h
    @author Stan Kladko
    @date 2018
*/

#pragma once


#include "messages/NetworkMessage.h"

class OracleProtocolInstance;


class OracleRequestBroadcastMessage : public NetworkMessage {
public:
    OracleRequestBroadcastMessage( block_id _blockID, uint64_t _timeMs, OracleAgent& sourceProtocolInstance );

    OracleRequestBroadcastMessage( node_id _srcNodeID, block_id _blockID,  uint64_t _timeMs, schain_id _schainId,
                        msg_id _msgID, schain_index _srcSchainIndex, const string & _ecdsaSig,
                        const string & _publicKey, const string & _pkSig, Schain* _sChain );
};
