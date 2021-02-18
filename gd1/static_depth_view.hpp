#ifndef GROUPDATA_STATIC_DEPTH_VIEW_HPP
#define GROUPDATA_STATIC_DEPTH_VIEW_HPP

#include "./groupdata.hpp"

   
#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    #include "./exception/exception.hpp"
#endif
#ifdef GROUPDATA_STATIC_DEPTH_VIEW_WARNING
    #include "./warning/warning.hpp"
#endif


namespace gd{

    //+++++++++++++++++++++++++++++//
    //    StaticDepthView Types    //
    //+++++++++++++++++++++++++++++//
    ////->    static_depth_view.hpp, static_depth_view.inl    <-//
    //(    gd::StaticDepthView Structure Template for Structure    )//
    template <typename T>
    struct StaticDepthView{
                
        //+    Member Variables    +//
        protected :
        const uint16_t _depth;
              T* const _ptr;
        

        //+    Static Functions    +//
        public :
        static constexpr size_t size (Empty =_key_) noexcept;
        

        //+    Member Functions    +//
        public :
        // Contruction Functions
        StaticDepthView (uint16_t, T*)               noexcept;
        StaticDepthView (const StaticDepthView<T>&) =default;
        StaticDepthView (StaticDepthView<T>&&)      =default;

        // Destruction Functions
        ~StaticDepthView (void) =default;
 
        // Reference functions
        uint16_t                        depth      (Empty =_key_)       const noexcept;
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
        template <uint16_t N>
        const T&                        path       (void)               const;
        const T&                        operator() (uint16_t)           const;       
    #else
        template <uint16_t N>
        const T&                        path       (void)               const noexcept;
        const T&                        operator() (uint16_t)           const noexcept;  
    #endif
        const StaticDepthView<const T>& operator[] (const size_t&)      const noexcept;
        const T*                        data       (void)               const noexcept;
              Range<const T>            range      (void)               const noexcept;
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
              Range<const T>            range      (uint16_t)           const;
              Range<const T>            range      (uint16_t, uint16_t) const;
    #else
              Range<const T>            range      (uint16_t)           const noexcept;
              Range<const T>            range      (uint16_t, uint16_t) const noexcept;
    #endif
        const StaticDepthView<const T>  view       (void)               const noexcept;
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
        const StaticDepthView<const T>  view       (uint16_t)           const;
        const StaticDepthView<const T>  view       (uint16_t, uint16_t) const;
    #else
        const StaticDepthView<const T>  view       (uint16_t)           const noexcept;
        const StaticDepthView<const T>  view       (uint16_t, uint16_t) const noexcept;
    #endif
        
        // Access Functions
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
        template <uint16_t N>
        T&                  path       (void);
        T&                  operator() (uint16_t);       
    #else
        template <uint16_t N>
        T&                  path       (void)               noexcept;
        T&                  operator() (uint16_t)           noexcept;       
    #endif
        StaticDepthView<T>& operator[] (const size_t&)      noexcept;
        T*                  data       (void)               noexcept;
        Range<T>            range      (void)               noexcept;
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
        Range<T>            range      (uint16_t);
        Range<T>            range      (uint16_t, uint16_t);
    #else
        Range<T>            range      (uint16_t)           noexcept;
        Range<T>            range      (uint16_t, uint16_t) noexcept;
    #endif
        StaticDepthView<T>  view       (void)               noexcept;
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
        StaticDepthView<T>  view       (uint16_t);
        StaticDepthView<T>  view       (uint16_t, uint16_t);
    #else
        StaticDepthView<T>  view       (uint16_t)           noexcept;
        StaticDepthView<T>  view       (uint16_t, uint16_t) noexcept;
    #endif

        // Binary Operators
        StaticDepthView<T>& operator= (const Range<T>&)           noexcept;
        StaticDepthView<T>& operator= (const StaticDepthView<T>&) noexcept;
        StaticDepthView<T>& operator= (std::initializer_list<T>)  noexcept;

        // Edit Functions
        StaticDepthView<T>& memset (int) noexcept;
    };
    



    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename T>
    std::ostream& operator<<(std::ostream&, const gd::StaticDepthView<T>&) noexcept;
    /*
    template <typename T>
    std::ostream& operator<<(std::ostream&, const gd::ElasticView<T>&) noexcept;
    */
}




//++++++++++++++++++++++++++//
//    Inline Definitions    //
//++++++++++++++++++++++++++//
#include "static_depth_view.inl"
//#include "conversion.inl"

#endif
