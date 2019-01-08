#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/ignore.hpp>
#include <eosiolib/transaction.hpp>

namespace eosio {
   /**
    * @defgroup eosiowrap eosio.wrap
    * @ingroup eosiocontracts
    * @brief eosio.wrap contract simplifies Block Producer superuser actions by making them more readable and easier to audit.

    * It does not grant block producers any additional powers that do not already exist within the 
    * system. Currently, 15/21 block producers can already change an account's keys or modify an 
    * account's contract at the request of ECAF or an account's owner. However, the current method 
    * is opaque and leaves undesirable side effects on specific system accounts. 
    * eosio.wrap allows for a cleaner method of implementing these important governance actions.
    * @{
    */
   class [[eosio::contract("eosio.wrap")]] wrap : public contract {
      public:
         using contract::contract;

         /**
          * Execute a transaction while bypassing regular authorization checks (requires authorization 
          * of eosio.wrap which needs to be a privileged account).
          */
         [[eosio::action]]
         void exec( ignore<name> executer, ignore<transaction> trx );

   };
   /** @}*/
} /// namespace eosio
