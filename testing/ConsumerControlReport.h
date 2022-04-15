/* -*- mode: c++ -*-
 * Copyright (C) 2020  Eric Paniagua (epaniagua@google.com)
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>  // for uint32_t
#include <vector>   // for vector

#include "kaleidoscope/driver/hid/keyboardio/usb/HID-Settings.h"                 // for HID_REPO...
#include "kaleidoscope/driver/hid/keyboardio/usb/MultiReport/ConsumerControl.h"  // for HID_Cons...

namespace kaleidoscope {
namespace testing {

class ConsumerControlReport {
 public:
  typedef HID_ConsumerControlReport_Data_t ReportData;

  static constexpr uint8_t kHidReportType = HID_REPORTID_CONSUMERCONTROL;

  ConsumerControlReport(const void *data);

  uint32_t Timestamp() const;
  std::vector<uint16_t> ActiveKeycodes() const;

 private:
  uint32_t timestamp_;
  ReportData report_data_;
};

}  // namespace testing
}  // namespace kaleidoscope
