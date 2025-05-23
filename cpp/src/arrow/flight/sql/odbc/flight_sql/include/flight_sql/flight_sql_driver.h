// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <arrow/flight/sql/odbc/odbcabstraction/include/odbcabstraction/diagnostics.h>
#include <arrow/flight/sql/odbc/odbcabstraction/include/odbcabstraction/spi/driver.h>

namespace driver {
namespace flight_sql {

class FlightSqlDriver : public odbcabstraction::Driver {
 private:
  odbcabstraction::Diagnostics diagnostics_;
  std::string version_;

 public:
  FlightSqlDriver();

  std::shared_ptr<odbcabstraction::Connection> CreateConnection(
      odbcabstraction::OdbcVersion odbc_version) override;

  odbcabstraction::Diagnostics& GetDiagnostics() override;

  void SetVersion(std::string version) override;

  void RegisterLog() override;
};

};  // namespace flight_sql
}  // namespace driver
