#ifndef GROUPDATA_VIEW_HPP
#define GROUPDATA_VIEW_HPP

#include "./groupdata.hpp"

   
#ifdef GROUPDATA_VIEW_EXCEPTION
    #include "./exception/exception.hpp"
#endif
#ifdef GROUPDATA_VIEW_WARNING
    #include "./warning/warning.hpp"
#endif


namespace gd{

    //++++++++++++++++++++//
    //    View Objects    //
    //++++++++++++++++++++//
    ////->    view.hpp, view.inl    <-//
    //(    gd::StaticDepthView Structure for Structure    )//
    template <typename T>
    struct StaticDepthView{
                
        //+    Member Variables    +//
        protected :
        const uint16_t _depth;
              T* const _elements;
        

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
        ~StaticDepthView (void) noexcept;
 
        // Reference functions
    #ifdef GROUPDATA_VIEW_EXCEPTION
        const T&                        operator() (uint16_t)           const;       
    #else
        const T&                        operator() (uint16_t)           const noexcept;       
    #endif
        const T*                        data       (void)               const noexcept;
        const StaticDepthView<const T>& operator[] (const size_t&)      const noexcept;
    #ifdef GROUPDATA_VIEW_EXCEPTION
              ConstRange<T>             range      (void)               const;
              ConstRange<T>             range      (uint16_t)           const;
              ConstRange<T>             range      (uint16_t, uint16_t) const;
        const StaticDepthView<const T>  view       (void)               const;
        const StaticDepthView<const T>  view       (uint16_t)           const;
        const StaticDepthView<const T>  view       (uint16_t, uint16_t) const;
    #else
              ConstRange<T>             range      (void)               const noexcept;
              ConstRange<T>             range      (uint16_t)           const noexcept;
              ConstRange<T>             range      (uint16_t, uint16_t) const noexcept;
        const StaticDepthView<const T>  view       (void)               const noexcept;
        const StaticDepthView<const T>  view       (uint16_t)           const noexcept;
        const StaticDepthView<const T>  view       (uint16_t, uint16_t) const noexcept;
    #endif
        
        // Access Functions
    #ifdef GROUPDATA_VIEW_EXCEPTION
        T&                  operator() (uint16_t);       
    #else
        T&                  operator() (uint16_t)           noexcept;       
    #endif
        T*                  data       (void)               noexcept;
        StaticDepthView<T>& operator[] (const size_t&)      noexcept;
    #ifdef GROUPDATA_VIEW_EXCEPTION
        Range<T>            range      (void);
        Range<T>            range      (uint16_t);
        Range<T>            range      (uint16_t, uint16_t);
        StaticDepthView<T>  view       (void);
        StaticDepthView<T>  view       (uint16_t);
        StaticDepthView<T>  view       (uint16_t, uint16_t);
    #else
        Range<T>            range      (void)               noexcept;
        Range<T>            range      (uint16_t)           noexcept;
        Range<T>            range      (uint16_t, uint16_t) noexcept;
        StaticDepthView<T>  view       (void)               noexcept;
        StaticDepthView<T>  view       (uint16_t)           noexcept;
        StaticDepthView<T>  view       (uint16_t, uint16_t) noexcept;
    #endif

        // Binary Operators
        StaticDepthView<T>& operator= (const StaticDepthView<T>&) noexcept;
        StaticDepthView<T>& operator= (std::initializer_list<T>)  noexcept;

        // Edit Functions
        StaticDepthView<T>& memset (int) noexcept;
    };
    
    
    /* 
    //->    view.hpp, view.inl    <-//
    //(    gd::DynamicView Structure for Lamination    )//
    template <typename T>
    struct DynamicView{
                
        //+    Member Variables    +//
        protected :
        const size_t&       _size;
        const size_t&       _capacity;
              T*      const _elements;
        

        //+    Static Functions    +//
        public :
        static constexpr uint16_t depth (Empty =_key_) noexcept;
        

        //+    Member Functions    +//
        public :
        // Contruction Functions
                 DynamicView      (const size_t&, const size_t&, T*) noexcept;
                 DynamicView      (const DynamicView<T>&)    noexcept;
                 DynamicView      (DynamicView<T>&&)=delete;
        template <typename... I>
        DynamicView<T>& construct (I...)              noexcept;

        // Destruction Functions
                 ~DynamicView    (void) noexcept;
        DynamicView<T>& destruct (void) noexcept;
 
        // Reference functions
        template<uint16_t N>
        auto          ref        (void)          const noexcept -> typename std::enable_if_t<(N==0), const T*>;
        const T*      ref        (uint16_t)      const noexcept;       
        const T*      spec       (void)          const noexcept;
        #ifdef GROUPDATA_VIEW_EXCEPTION
        const T&      operator() (const size_t&) const;
        #else
        const T&      operator() (const size_t&) const noexcept;
        #endif
        const size_t& size       (Empty =_key_)  const noexcept;
        const size_t& capacity   (Empty =_key_)  const noexcept;

        // Access Functions
        template<uint16_t N>
        auto path       (void)               noexcept -> typename std::enable_if_t<(N==0), T*>;
        T*   path       (uint16_t)           noexcept; 
        T*   data       (void)               noexcept;
        #ifdef GROUPDATA_VIEW_EXCEPTION
        T&       operator[] (const size_t&);
        #else
        T&       operator[] (const size_t&)  noexcept;
        #endif

        // Edit Functions
        DynamicView<T>& memset (uint32_t)      noexcept;
    };
    
    
    
    //(    gd::DynamicClassView Structure for Lamination    )//
    template <typename T>
    struct DynamicClassView{
                
        //+    Member Variables    +//
        protected :
        const size_t&       _size;
        const size_t&       _capacity;
              T*      const _elements;
        

        //+    Static Functions    +//
        public :
        static constexpr uint16_t depth (Empty =_key_) noexcept;
        

        //+    Member Functions    +//
        public :
        // Contruction Functions
                        DynamicClassView (const size_t&, const size_t&, T*) noexcept;
                        DynamicClassView (const DynamicClassView<T>&)            noexcept;
                        DynamicClassView (DynamicClassView<T>&&)=delete;
        template <typename... I>
        DynamicClassView<T>& construct   (I...)                             noexcept;

        // Destruction Functions
                 ~DynamicClassView    (void) noexcept;
        DynamicClassView<T>& destruct (void) noexcept;
 
        // Reference functions
        template<uint16_t N>
              auto    ref        (void)          const noexcept -> typename std::enable_if_t<(N==0), const T*>;
        const T*      ref        (uint16_t)      const noexcept;
        const T*      spec       (void)          const noexcept;
        #ifdef GROUPDATA_VIEW_EXCEPTION
        const T&      operator() (const size_t&) const;
        #else
        const T&      operator() (const size_t&) const noexcept;
        #endif
        const size_t& size       (Empty =_key_)  const noexcept;
        const size_t& capacity (  Empty =_key_)  const noexcept;

        // Access Functions
        template<uint16_t N>
        auto     path       (void)           noexcept -> typename std::enable_if_t<(N==0), T*>;
        T*       path       (uint16_t)       noexcept; 
        T*       data       (void)           noexcept;
        #ifdef GROUPDATA_VIEW_EXCEPTION
        T&       operator[] (const size_t&);
        #else
        T&       operator[] (const size_t&)  noexcept;
        #endif
    
    };

    */
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



/*
//++++++++++++++++++++++++++//
//    Inline Definitions    //
//++++++++++++++++++++++++++//
#include "view.inl"
#include "conversion.inl"
*/
#endif
