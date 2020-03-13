/*
** EPITECH PROJECT, 2020
** error
** File description:
** Error
*/

#pragma once

class Error : public std::exception {
    public:
        std::string SendMessage() {return _ErrorMessage;}
        Error(std::string ErrorMessage) : _ErrorMessage(ErrorMessage) {}
        ~Error() {}

    private:
        std::string _ErrorMessage;
};
