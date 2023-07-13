#include "webshop.hpp"
//ako koristimo konst ne mozemo promeniti taj podatak u funkciji
void webshop::signup(inery::name username,std::string password_hash,std::string email,
    std::string name,std::string phone,std::string address,std::string role){
        //da bi se napravaila tabela potrebno je da je napravi vlasink kontrakta
        require_auth(get_self());
        //code i scope korsiti se od kreatora kontrakta
        users_t users(get_self(),get_self().value);
        //auto je ako ne znamo koju vrstu podataka u nosimo
        users.emplace(get_self(), [&](user &user){
            user.username=username;
            user.password_hash=password_hash;
            user.email=email;
            user.name=name;
            user.phone=phone;
            user.address=address;
            user.role=role;

        });
    }
