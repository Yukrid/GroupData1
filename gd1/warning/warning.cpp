#ifndef GROUPDATA_WARNING_WARNING_CPP
#define GROUPDATA_WARNING_WARNING_CPP

#include "warning.hpp"

#include <sstream>

namespace gd::warning{

    //++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::base_warning Void    //
    //++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    template <typename T>
    std::string base_warning::to_string(const T& t_) const noexcept
    {
       std::stringstream ss1;
       ss1<<t_;

       return ss1.str();
    }



    //(    gd::warning::failed_to_realloc Void    )//
    //+    Member Function    +//
    // Construction Function
    failed_to_realloc::failed_to_realloc(const std::string& str_, const void* ptr_, const size_t& size_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Failed to Realloc.\n  (Pointer -> "+to_string<const void*>(ptr_)+", Requested Size -> "+to_string<size_t>(size_)+")\n"<<std::endl;

        return;
    }
    
    
    
    //(    gd::warning::failed_to_malloc Void    )//
    //+    Member Function    +//
    // Construction Function
    failed_to_malloc::failed_to_malloc(const std::string& str_, const size_t& size_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Failed to Malloc.\n  (Requested Size -> "+to_string<size_t>(size_)+")\n"<<std::endl;

        return;
    }




    //+++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::exceeded_size Void    //
    //+++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Construction Function
    exceeded_size::exceeded_size(const std::string& str_, const size_t& size_, const size_t& index_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Exceeded Size.\n  (Size > Index -> "+to_string<size_t>(size_)+" > "+to_string<size_t>(index_)+")\n"<<std::endl;

        return;
    }
    
    
    
    
    //+++++++++++++++++++++++++++++++++++++//
    //    gd::warning::double_free Void    //
    //+++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Construction Function
    double_free::double_free(const std::string& str_, const std::string& name_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Double Free.\n  (Variable Name -> "+name_+")\n"<<std::endl;

        return;
    }



    
    //+++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::double_delete Void    //
    //+++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Construction Function
    double_delete::double_delete(const std::string& str_, const std::string& name_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Double Delete.\n  (Variable Name -> "+name_+")\n"<<std::endl;

        return;
    }




    //++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::warning::ignored_size_index Void    //
    //++++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Construction Function
    ignored_size_index::ignored_size_index(const std::string& str_, const size_t& id_) noexcept
    {
        std::cout<<"  what() :  "+str_+"\n  warning:  Ignored Index. (This structure have a depth, not a size. So, \"operator()\" should be used to access a array element.)\n  (Inputted Index -> "+std::to_string(id_)+")\n"<<std::endl;

        return;
    }
}
#endif
