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

    @file NetworkMessageEnvelope.h
    @author Stan Kladko
    @date 2018
*/

#pragma  once

class NodeInfo;

class NetworkMessage;
class Node;
class ProtocolKey;

#include "MessageEnvelope.h"


class NetworkMessageEnvelope : public MessageEnvelope {

    uint64_t arrivalTime = 0;

public:
    NetworkMessageEnvelope(const ptr <NetworkMessage> &message,
                           schain_index _senderIndex);

    [[nodiscard]] uint64_t getArrivalTime() const;

};

