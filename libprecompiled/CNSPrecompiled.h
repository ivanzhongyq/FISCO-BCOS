/*
 * @CopyRight:
 * FISCO-BCOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FISCO-BCOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>
 * (c) 2016-2018 fisco-dev contributors.
 */
/** @file CNSPrecompiled.h
 *  @author chaychen
 *  @date 20181119
 */
#pragma once
#include "Common.h"

namespace dev
{
const std::string SYS_CNS_FIELD_NAME = "name";
const std::string SYS_CNS_FIELD_VERSION = "version";
const std::string SYS_CNS_FIELD_ADDRESS = "address";
const std::string SYS_CNS_FIELD_ABI = "abi";

namespace precompiled
{
class CNSPrecompiled : public dev::blockverifier::Precompiled
{
public:
    typedef std::shared_ptr<CNSPrecompiled> Ptr;
    CNSPrecompiled();
    virtual ~CNSPrecompiled(){};

    std::string toString() override;

    bytes call(std::shared_ptr<dev::blockverifier::ExecutiveContext> context, bytesConstRef param,
        Address const& origin = Address()) override;
};

}  // namespace precompiled

}  // namespace dev