/*
    Copyright (C) 2019 SKALE Labs

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

    @file PartialHash.h
    @author Stan Kladko
    @date 2019
*/

#ifndef CONSENSUS_PARTIALSHA3HASH_H
#define CONSENSUS_PARTIALSHA3HASH_H


#include "SkaleCommon.h"

class PartialHash {

    ptr<array<uint8_t ,PARTIAL_HASH_LEN>> hash;

public:

    explicit PartialHash(const ptr<array<uint8_t, PARTIAL_HASH_LEN>>& _hash);

    static ptr< PartialHash >  hex2sha(const string& _hex );

    void print();

    uint8_t at(uint32_t _position);

    int compare(const ptr<PartialHash>& _hash2 );

    uint8_t * data() {
        return hash->data();
    };

    ptr<PartialHash> fromHex(const string& _hex);

    string toHex();


};


#endif