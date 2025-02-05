#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include <iostream>
#include <cstring>
namespace sdds {
    Status::Status(const char* Description ){
        if (Description != nullptr && strlen(Description) > 0){
            description = new char[strlen(Description) + 1] ; 
            strcpy(description , Description) ; 
        }else {
            description = nullptr ; 

        } ;

        errorCode = 0 ;
    } ;

    Status::~Status(){
        delete [] description ;

    } ; 

    Status::Status(const Status& srcStatus){
        if(srcStatus.description != nullptr){
            description = new char[strlen(srcStatus.description) + 1] ;
            strcpy(description, srcStatus.description) ; 
        }else {
            description = nullptr ;

        } ; 


        errorCode = srcStatus.errorCode ; 
    } ;

    Status& Status::operator=(const Status& srcStatus){
        delete [] description ; 
        if(srcStatus.description != nullptr){
            description = new char[strlen(srcStatus.description)+1] ;
            strcpy(description,srcStatus.description) ;  

        } else {
            description = nullptr ;

        } ;

        errorCode = srcStatus.errorCode ;

        return *this ; 
    } ;
    Status& Status::operator=(int newCode){
        errorCode = newCode ; 

        return *this ;

    }  ; 
    Status& Status::operator=(const char* newDescription){
        delete [] description ; 
        if (newDescription != nullptr && strlen(newDescription) > 0){
            description = new char[strlen(newDescription)+1] ;
            strcpy(description,newDescription) ;  

        }else {
            description = nullptr ;
        } ; 
    return *this ; 
    } ; 
    Status::operator int() const {
        return errorCode ; 

    } ; 

    Status::operator const char *() const {

        return description ; 

    };

    Status::operator bool() const{
        bool objectValid ; 
        if (description != nullptr && strlen(description) > 0){
            objectValid = false ; 

        }else {
            objectValid = true  ; 
        } ;
        return objectValid ;
    } ; 


    Status& Status::clear(){
        delete [] description ; 
        description = nullptr ; 
        errorCode = 0 ;

        return *this ; 

    }; 

    std::ostream& operator<<(std::ostream& os, const Status& status){
        if (int(status) != 0){
            os << "ERR#" << (int)status <<": " ;  

        } ; 
        if (bool(status) == false){
            os <<  (const char*)status ;  

        } ;
        return os ; 

    } ; 
    void Status::set(const char* Description , int code){
        
        if (Description != nullptr && strlen(Description) > 0){
        delete [] description ; 
        description = new char[strlen(Description)+1]  ;
        strcpy(description, Description) ;  
        }else {
           description = nullptr ; 
        } ; 
        errorCode = code ; 

    } ; 


}
