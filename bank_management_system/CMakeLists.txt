# CMakeList.txt : CMake project for bank_management_system, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (bank_management_system "bank_management_system.cpp" "bank_management_system.h" "clsAddNewClientScreen.h" "clsAddNewUserScreen.h" "clsBankClient.h" "clsClientListScreen.h" "clsCurrenciesListScreen.h" "clsCurrency.h" "clsCurrencyCalculatorScreen.h" "clsCurrencyExchangeMainScreen.h" "clsDate.h" "clsDeleteClientScreen.h" "clsDeleteUserScreen.h" "clsDepositScreen.h" "clsFindClientScreen.h" "clsFindCurrencyScreen.h" "clsFindUserScreen.h" "clsLoginRegisterScreen.h" "clsLoginScreen.h" "clsMainScreen.h" "clsManageUsers.h" "clsPerson.h" "clsScreen.h" "clsString.h" "clsTotalBalancesScreen.h" "clsTransactionsScreen.h" "clsTransferLogScreen.h" "clsTransferScreen.h" "clsUpdateClientScreen.h" "clsUpdateCurrencyRateScreen.h" "clsUpdateUserScreen.h" "clsUser.h" "clsUsersListScreen.h" "clsUtil.h" "clsWithDrawScreen.h" "Global.h" "inputValidate.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bank_management_system PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
