#include "exception.hpp"

#include <sstream>

namespace gd::exception{

    //++++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::base_exception Void    //
    //++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    template <typename T>
    std::string base_exception::to_string(const T& t_) const noexcept{
        
        std::stringstream ss1;
        ss1<<t_;

        return ss1.str();
    }




    //++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::failed_to_malloc Void    //
    //++++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    failed_to_malloc::failed_to_malloc(const std::string& str_, const size_t& size_)
        : std::runtime_error{ std::stringstream{ str_+"\n  Error :  Failed to Malloc.\n  (Requested Size -> "+to_string<size_t>(size_)+")" }.str() }
    {   
        return;
    }
    
    


    //+++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::failed_to_realloc Void    //
    //+++++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    failed_to_realloc::failed_to_realloc(const std::string& str_, const void* ptr_, const size_t& size_)
        : std::runtime_error{ std::stringstream{ str_+"\n  Error :  Failed to Realloc.\n  (Pointer -> "+to_string<const void*>(ptr_)+", Requested Size -> "+to_string<size_t>(size_)+")"}.str() }
    {
        return;
    }
    
    
    
    
    //+++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::failed_to_new Void    //
    //+++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    failed_to_new::failed_to_new(const std::string& str_, const size_t& size_)
        : std::runtime_error{ std::stringstream{ str_+"\n  Error :  Failed to New.\n  (Size -> "+to_string<size_t>(size_)+")" }.str() }
    {   
        return;
    }




    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::exceeded_capacity_in_size_direction Void    //
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    exceeded_capacity_in_size_direction::exceeded_capacity_in_size_direction(const std::string& str_, const size_t& capacity_, const size_t& index_)
        : std::runtime_error{ std::stringstream{ str_+"\n  Error :  Exceeded Capacity in Size Direction.\n  (Capacity > Index -> "+to_string<size_t>(capacity_)+" > "+to_string<size_t>(index_)+")"}.str() }
    {
        return;
    }
    
  
  

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //    gd::exception::exceeded_capacity_in_depth_direction Void    //
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //+    Member Function    +//
    // Constant Function
    exceeded_capacity_in_depth_direction::exceeded_capacity_in_depth_direction(const std::string& str_, const size_t& capacity_, const size_t& index_)
        : std::runtime_error{ std::stringstream{ str_+"\n  Error :  Exceeded Capacity in Depth Direction.\n  (Capacity > Index -> "+to_string<size_t>(capacity_)+" > "+to_string<size_t>(index_)+")"}.str() }
    {
        return;
    }
}
