/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014-2021,  Regents of the University of California.
 *
 * This file is part of ndn-tools (Named Data Networking Essential Tools).
 * See AUTHORS.md for complete list of ndn-tools authors and contributors.
 *
 * ndn-tools is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndn-tools is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndn-tools, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NDN_TOOLS_DISSECT_NDN_DISSECT_HPP
#define NDN_TOOLS_DISSECT_NDN_DISSECT_HPP

#include "core/common.hpp"

#include <ndn-cxx/encoding/block.hpp>

namespace ndn {
namespace dissect {

class NdnDissect : noncopyable
{
public:
  NdnDissect(std::istream& input, std::ostream& output);

  void
  dissect();

private:
  void
  printBranches();

  void
  printType(uint32_t type);

  void
  printBlock(const Block& block);

private:
  std::istream& m_in;
  std::ostream& m_out;

  // m_branches[i] is true iff the i-th level of the tree has more branches after the current one
  std::vector<bool> m_branches;
};

} // namespace dissect
} // namespace ndn

#endif // NDN_TOOLS_DISSECT_NDN_DISSECT_HPP
