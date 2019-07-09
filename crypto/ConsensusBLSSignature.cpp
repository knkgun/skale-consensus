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

    @file ConsensusBLSSignature.cpp
    @author Stan Kladko
    @date 2019
*/


#include "../Log.h"
#include "../SkaleCommon.h"
#include "../crypto/bls_include.h"
#include "../network/Utils.h"
#include "../thirdparty/json.hpp"

#include "BLSSignature.h"
#include "ConsensusBLSSignature.h"


ConsensusBLSSignature::ConsensusBLSSignature(
    ptr< string > _s, block_id _blockID, size_t _totalSigners, size_t _requiredSigners )
    : BLSSignature( _s, _totalSigners, _requiredSigners ), blockId( _blockID ) {}

block_id ConsensusBLSSignature::getBlockId() const {
    return blockId;
}


ConsensusBLSSignature::ConsensusBLSSignature( ptr< libff::alt_bn128_G1 > _s, block_id _blockID,
    size_t _totalSigners, size_t _requiredSigners )
    : BLSSignature( _s, _totalSigners, _requiredSigners ), blockId( _blockID ){};