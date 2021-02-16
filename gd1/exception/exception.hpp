#ifndef GROUPDATA_EXCEPTION_EXCEPTION_HPP
#define GROUPDATA_EXCEPTION_EXCEPTION_HPP

#include <iostream>

namespace gd::exception{

    //+++++++++++++++++++++++//
    //    Exception Types    //
    //+++++++++++++++++++++++//
    //(    gd::exception::base_exception Void    )//
    struct base_exception{
            
        //+    Member Function    +//
        // Constant Function
        template <typename T>
        std::string to_string (const T&) const noexcept;     
    
    };



    //(    gd::exception::failed_to_malloc Void    )//
    struct failed_to_malloc : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        failed_to_malloc (const std::string&, const size_t&);
    
    };



    //(    gd::exception::failed_to_realloc Void    )//
    struct failed_to_realloc : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        failed_to_realloc (const std::string&, const void*, const size_t&);
    
    };
     


    //(    gd::exception::failed_to_new Void    )//
    struct failed_to_new : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        failed_to_new (const std::string&, const size_t&);
    
    };


    
    //(    gd::exception::exceeded_capacity_in_size_direction Void    )//
    struct exceeded_capacity_in_size_direction : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        exceeded_capacity_in_size_direction (const std::string&, const size_t&, const size_t&);
        
    };
    


    //(    gd::exception::exceeded_capacity_in_depth_direction Void    )//
    struct exceeded_capacity_in_depth_direction : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        exceeded_capacity_in_depth_direction (const std::string&, const size_t&, const size_t&);
    
    };



    //(    gd::exception::generation_of_over_range Void    )//
    struct generation_of_over_range : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        generation_of_over_range (const std::string&, const size_t&, const size_t&);
    
    };



    //(    gd::exception::generation_of_backward_range Void    )//
    struct generation_of_backward_range : public base_exception, public std::runtime_error{
    
        //+    Member Function    +//
        // Construction Function
        generation_of_backward_range (const std::string&, const size_t&, const size_t&);

    };


}
#endif
