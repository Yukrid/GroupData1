#ifndef GROUPDATA_GROUP_HPP
#define GROUPDATA_GROUP_HPP

#include "./groupdata.hpp"
#include "./static_depth_view.hpp"

#ifdef GROUPDATA_GROUP_EXCEPTION
#include "./exception/exception.hpp"
#endif
#ifdef GROUPDATA_GROUP_WARNING
#include "./warning/warning.hpp"
#endif

namespace gd {

    //+++++++++++++++++++//
    //    Group Types    //
    //+++++++++++++++++++//
    //->    group.hpp, group.inl    <-//
    //(    gd::Group<T,D> Structure Template for Structure    )//
    template <typename T, uint16_t D>
    struct Group {
    
        //+    Static Functions    +//
        public:
        static constexpr uint16_t depth (Empty = _key_) noexcept;
        static constexpr size_t   size  (Empty = _key_) noexcept;
     
        
        //+    Member Variables    +//
        protected:
        T _elements[D];
    
       
        //+    Member Functions    +//
        public:
        // Contruction Functions
                    Group     (void)                     noexcept;
                    Group     (const Group<T,D>&)        noexcept;
                    Group     (Group<T,D>&&)             noexcept;
                    Group     (std::initializer_list<T>) noexcept;
        Group<T,D>& construct (void)                     noexcept;
        Group<T,D>& construct (const Group<T,D>&)        noexcept;
        Group<T,D>& construct (Group<T,D>&&)             noexcept;
        Group<T,D>& construct (std::initializer_list<T>) noexcept;
    
        // Destruction Functions
                    ~Group    (void) noexcept;
        Group<T,D>&  destruct (void) noexcept;
    
        // Reference Functions
        template <uint16_t N>
              auto                     path       (void)               const noexcept -> typename std::enable_if_t<(N < D), const T&>;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        const T&                       operator() (uint16_t)           const;
    #else
        const T&                       operator() (uint16_t)           const noexcept;
    #endif
        const Group<T,D>&              operator[] (const size_t&)      const noexcept;
        const T*                       data       (void)               const noexcept;
    #ifdef GROUPDATA_GROUP_EXCEPTION
              Range<const T>            range      (uint16_t =D)        const;
              Range<const T>            range      (uint16_t, uint16_t) const;
    #else
              Range<const T>            range      (uint16_t =D)        const noexcept;
              Range<const T>            range      (uint16_t, uint16_t) const noexcept;
    #endif
    #ifdef GROUPDATA_GROUP_EXCEPTION
        const StaticDepthView<const T> view       (uint16_t =D)        const;
        const StaticDepthView<const T> view       (uint16_t, uint16_t) const;
    #else
        const StaticDepthView<const T> view       (uint16_t =D)        const noexcept;
        const StaticDepthView<const T> view       (uint16_t, uint16_t) const noexcept;
    #endif

        // Access Functions
        template <uint16_t N>
        auto               path       (void)               noexcept -> typename std::enable_if_t<(N < D), T&>;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        T&                 operator() (uint16_t);
    #else
        T&                 operator() (uint16_t)           noexcept;
    #endif
        Group<T,D>&        operator[] (const size_t&)      noexcept;
        T*                 data       (void)               noexcept;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        Range<T>           range      (uint16_t =D);
        Range<T>           range      (uint16_t, uint16_t);
    #else
        Range<T>           range      (uint16_t =D)        noexcept;
        Range<T>           range      (uint16_t, uint16_t) noexcept;
    #endif
    #ifdef GROUPDATA_GROUP_EXCEPTION
        StaticDepthView<T> view       (uint16_t =D);
        StaticDepthView<T> view       (uint16_t, uint16_t);
    #else
        StaticDepthView<T> view       (uint16_t =D)        noexcept;
        StaticDepthView<T> view       (uint16_t, uint16_t) noexcept;
    #endif

        // Binary Operator
        Group<T,D>& operator= (const Group<T,D>&)         noexcept;
        Group<T,D>& operator= (Group<T,D>&&)              noexcept;
        Group<T,D>& operator= (std::initializer_list<T>)  noexcept;
        Group<T,D>& operator= (const Range<T>&)           noexcept;
        Group<T,D>& operator= (const Range<const T>&)      noexcept;
        Group<T,D>& operator= (const StaticDepthView<T>&) noexcept;
        
        // Edit Functions
        Group<T,D>& memset (int) noexcept;

        // Casting Functions
        template <uint16_t E>
        operator Group<T,E>() const noexcept;
        template <typename U, uint16_t E>
        operator Group<U,E>() const noexcept;

    };
    
   

    //(    gd::ClassGroup<T,D> Structure Template for Class    )//
    template <typename T, uint16_t D>
    struct ClassGroup {
    
        //+    Static Functions    +//
        public:
        static constexpr uint16_t depth (Empty = _key_) noexcept;
        static constexpr size_t   size  (Empty = _key_) noexcept;
    
    
        //+    Member Variables    +//
        protected:
        T _elements[D];
    
    
        //+    Member Functions    +//
        public:
        // Contruction Functions
                          ClassGroup (void)                     noexcept;
                          ClassGroup (const ClassGroup<T,D>&)  noexcept;
                          ClassGroup (ClassGroup<T,D>&&)       noexcept;
                          ClassGroup (std::initializer_list<T>) noexcept;
        ClassGroup<T,D>& construct  (void)                     noexcept;
        ClassGroup<T,D>& construct  (const ClassGroup<T,D>&)   noexcept;
        ClassGroup<T,D>& construct  (ClassGroup<T,D>&&)        noexcept;
        ClassGroup<T,D>& construct  (std::initializer_list<T>) noexcept;
        
        // Destruction Functions
                          ~ClassGroup (void) noexcept;
        ClassGroup<T,D>&  destruct   (void) noexcept;
    
        // Reference Functions
        template <uint16_t N>
              auto             path       (void)               const noexcept -> typename std::enable_if_t<(N < D), const T&>;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        const T&               operator() (uint16_t)           const;
    #else
        const T&               operator() (uint16_t)           const noexcept;
    #endif
        const ClassGroup<T,D>* data       (void)               const noexcept;
        const ClassGroup<T,D>& operator[] (const size_t&)      const noexcept;
    #ifdef GROUPDATA_GROUP_EXCEPTION
              Range<const T>   range      (uint16_t =D)        const;
              Range<const T>   range      (uint16_t, uint16_t) const;
    #else
              Range<const T>   range      (uint16_t =D)        const noexcept;
              Range<const T>   range      (uint16_t, uint16_t) const noexcept;
    #endif
    
        // Access Functions
        template <uint16_t N>
        auto             path       (void)               noexcept -> typename std::enable_if_t<(N < D), T&>;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        T&               operator() (uint16_t);
    #else
        T&               operator() (uint16_t)           noexcept;
    #endif
        ClassGroup<T,D>* data       (void)               noexcept;
        ClassGroup<T,D>& operator[] (const size_t&)      noexcept;
    #ifdef GROUPDATA_GROUP_EXCEPTION
        Range<T>         range      (uint16_t =D);
        Range<T>         range      (uint16_t, uint16_t);
    #else
        Range<T>         range      (uint16_t =D)        noexcept;
        Range<T>         range      (uint16_t, uint16_t) noexcept;
    #endif
   
        // Binary Operator
        ClassGroup<T,D>& operator= (const ClassGroup<T,D>&)   noexcept;
        ClassGroup<T,D>& operator= (ClassGroup<T,D>&&)        noexcept;
        ClassGroup<T,D>& operator= (std::initializer_list<T>) noexcept;

        // Casting Functions
        template <typename U, uint16_t E>
        operator ClassGroup<U, E> () const noexcept;
    };


    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename T, uint16_t D>
    std::ostream& operator<<(std::ostream&, const gd::Group<T,D>&) noexcept;
    template <typename T, uint16_t D>
    std::ostream& operator<<(std::ostream&, const gd::ClassGroup<T,D>&) noexcept;
}


//++++++++++++++++++++++++++//
//    Inline Definitions    //
//++++++++++++++++++++++++++//
#include "group.inl"

#endif
