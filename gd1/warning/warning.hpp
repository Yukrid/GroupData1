#ifndef GROUPDATA_WARNING_WARNING_HPP
#define GROUPDATA_WARNING_WARNING_HPP

#include <iostream>

namespace gd::warning{


    //++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::base_warning Void    //
    //++++++++++++++++++++++++++++++++++++++//
    struct base_warning{
        
        //+    Member Function    +//
        // Constant Function
        template <typename T>
        std::string to_string(const T&) const noexcept;
    
    };
    



    //(    gd::warning::failed_to_realloc Void    )//
    struct failed_to_realloc : public base_warning{

        //+    Member Function    +//
        // Construction Function
        failed_to_realloc(const std::string&, const void*, const size_t&) noexcept;

    };



    //(    gd::warning::failed_to_malloc Void    )//
    struct failed_to_malloc : public base_warning{

        //+    Member Function    +//
        // Construction Function
        failed_to_malloc(const std::string&, const size_t&) noexcept;

    };




    //+++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::exceeded_size Void    //
    //+++++++++++++++++++++++++++++++++++++++//
    struct exceeded_size : public base_warning{

        //+    Member Function    +//
        // Construction Function
        exceeded_size(const std::string&, const size_t&, const size_t&) noexcept;

    };
    



    //+++++++++++++++++++++++++++++++++++++//
    //    gd::warning::double_free Void    //
    //+++++++++++++++++++++++++++++++++++++//
    struct double_free : public base_warning{

        //+    Member Function    +//
        // Construction Function
        double_free(const std::string&, const std::string&) noexcept;

    };




    //+++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::double_delete Void    //
    //+++++++++++++++++++++++++++++++++++++++//
    struct double_delete : public base_warning{

        //+    Member Function    +//
        // Construction Function
        double_delete(const std::string&, const std::string&) noexcept;

    };
    
/* 
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::implicit_converson_with_different_depth Void    //
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //(    gd::warning::implicit_conversion_with_different_depth Void    )//
    struct implicit_conversion_with_defferent_depth : public base_warning{

        //+    Member Function    +//
        // Construction Function
        implicit_conversion_with_defferent_depth(const std::string&, const uint16_t, const uint16_t) noexcept;

    };
*/


    //++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::ignored_size_index Void    //
    //++++++++++++++++++++++++++++++++++++++++++++//
    struct ignored_size_index : public base_warning{

        //+    Member Function    +//
        // Construction Function
        ignored_size_index (const std::string&, const size_t&) noexcept;

    };
    
}

#endif
