#include <inery/inery.hpp>
using namespace inery;
//deklarisemo strukture i ostale deklaracije u hpp, a u cpp pravimo akcije
//namespace koristimo ako ne zelimo da pisemo iz koje biblioteke vadimo funkciju, nije praksa
//da se koristi za standardnu jer se moze desiti da u dve bibliotke bude ista funkcija

//pocetak je uvek isti class [[inery::contract]] ime :public contract{}
class [[inery::contract]] webshop :public contract{
public :

    using contract::contract;
//konstruktor ime(name reciever,name code,datastream<const char*> ds): contract(receiver,code,ds){}
    webshop(name receiver,name code, datastream<const char*> ds)
    : contract(receiver,code,ds){}
    //kada imamo tabelu potrebno je da imamo primary key, on je uvek uint64
    struct [[inery::table]] user{
        inery::name username;
        std::string password_hash;
        std::string name;
        std::string phone;
        std::string email;
        std::string address;
        std::string role;

        uint64_t primary_key() const{return username.value;}

    };
    struct [[inery::table]] product{
        uint64_t id;

        std::string name;
        std::string desc;
        std::string unit;

        double price;
        double quantity;

        uint64_t primary_key() const{return id;}
    };
    struct order_item{
        uint64_t product_id;
        double quantity;
        double product_price;
        double total_price;
    };
    struct [[inery::table]] oreder{
        uint64_t id;
        std::string user;
        inery::name username;
        std::vector<order_item> items;
        time_point order_data;
        time_point expected_delevery_data;
        std::string status;
        
        uint64_t primary_key() const{return id;}

    };
    //typedef dajemo naziv nekom objektu u ovom slucaju multi_index tabeli
    //typedef inery::mulit_index<naziv_n,vrsta> ime_koje_mu_dajemo
    typedef inery::multi_index<"users"_n,user> users_t;
    typedef inery::multi_index<"oreders"_n,oreder> oreder_t;
    typedef inery::multi_index<"products"_n,product> product_t;

    //deklaracija akcije [[inery::action]] void/uint.. naziv(parametri);
    [[inery::action]] void signup(inery::name username,std::string password_hash,std::string email,
    std::string name,std::string phone,std::string address,std::string role);


};
 //naziv fajla
