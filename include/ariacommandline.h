/* -----------------------------------------------------------------------------
 * 
 * Name:    commandline.h
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Syntax: None
 * 
 * Description: Stuff
 * 
 * Notes: None
 * 
 * -----------------------------------------------------------------------------
 */

/* Header guard */
#ifndef ARIA_COMMAND_LINE_H
#define ARIA_COMMAND_LINE_H

/* Includes */
#include "ariadef.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

ARIA_NAMESPACE

namespace commandline
{
    enum argument_t
    {
        no_argument,
        required_argument,
        optional_argument,
        list_argument
    };
    typedef struct option option_t;

    struct option
    {
        std::string shortopt;
        std::string longopt;
        std::string name;
        argument_t  argument;
        std::string desc;

        /*
        friend bool operator==(const option_t&, const option_t&);
        virtual bool is_equal(const option_t& opt) const {
            return ((opt.shortopt == this->shortopt) \
                    && (opt.longopt == this->longopt) \
                    && (opt.name == this->name) \
                    && (opt.argument == this->argument));
        }
        */
    };


    
    // typedef struct optlist_t
    // {
    //     std::vector<option_t> list;

    //     /**
    //      * Find option in option list
    //      */
    //     // option_t find(std::string opt) {
    //     //     option_t o;
    //     //     for (option_t option : list) {
    //     //         std::cout << option.longopt << std::endl;
    //     //         if (list.back() == option) {
    //     //             o = option;
    //     //         }
    //     //     }
    //     //     return o;
    //     // }
    // } optlist_t;

    typedef std::vector<option_t> optlist_t;
    typedef std::unordered_map<std::string, std::string> keyval_t;

    using values = std::map<std::string, std::string>;

    class interface
    {
    public:
        explicit interface(const optlist_t options);

        void usage(void);
        void parse(char** argv);
        std::string get(std::string opt);
        bool has(std::string opt);

    private:
        const optlist_t m_options;
        keyval_t m_table;
    };

    // class option;
    // using choices = std::vector<std::string>;
    // using options = std::vector<option>;
    // using values = std::map<std::string, std::string>;

    // class option
    // {
    // public:
    //     std::string shortflag;
    //     std::string longflag;
    //     std::string desc;
    //     std::string token;
    //     const choices values;

    //     explicit option(std::string&& shortflag, std::string&& longflag,
    //                     std::string&& desc, std::string&& token = "",
    //                     const choices&& c = {})
    //         : shortflag(std::forward<std::string>(shortflag))
    //         , longflag(std::forward<std::string>(longflag))
    //         , desc(std::forward<std::string>(desc))
    //         , token(std::forward<std::string>(token))
    //         , values(std::forward<const choices>(c)) {}
    // };

    // class parser
    // {
    // public:
    //     using make_type = std::shared_ptr<parser>;
    //     static make_type init(const options&& opts);
    //     explicit parser(const options&& opts);

    //     void usage(void) const;
    //     void process_input(const std::vector<std::string>& values);
    //     void process_config(void);
    //     std::string get_value(std::string opt);
    //     values get_values(void);
    //     bool has_option(const std::string& opt) const;

    // protected:
    //     std::string parse_value(std::string current, const std::string& next, std::string token, choices values);
    //     std::string parse_value(std::string current, const std::string& next, choices values);
    //     std::string set_value(option opt, std::string current, std::string next);
    //     std::string set_value(std::string opt, std::string value);
    //     bool is_short(const std::string& opt, const std::string& optshort) const;
    //     bool is_long(const std::string& opt, const std::string& optlong) const;
    //     bool is(const std::string& opt, std::string optshort, std::string optlong) const;

    // private:
    //     const options m_opts;
    //     values m_optvalues{};
    // };

}

// bool operator==(const commandline::option_t& a, const commandline::option_t& b) {
//     return typeid(a) == typeid(b) // Allow compare only instances of the same dynamic type
//            && a.is_equal(b);       // If types are the same then do the comparision.
// }

ARIA_NAMESPACE_END

#endif /* ARIA_COMMAND_LINE_H */
