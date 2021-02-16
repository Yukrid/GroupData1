#ifndef GROUPDATA_ALTERNATIVE_HPP
#define GROUPDATA_ALTERNATIVE_HPP

#include "./groupdata.hpp"

namespace gd{

    //+++++++++++++++++++++++++++//
    //    Alternative Objects    //
    //+++++++++++++++++++++++++++//    
    //(    gd::Numbered for Lamination    )//
    template <uint16_t R, typename T>
    struct Numbered{

        public :
        //+    Member Variables    +//
        T value;
        
         
        //+    Member Functions    +//
        // Construction Function
        Numbered (void)                   noexcept;
        Numbered (const T&)               noexcept;
        Numbered (T&&)                    noexcept;
        Numbered (const Numbered<R, T>&) =default;
        Numbered (Numbered<R, T>&&)      =default;

        // Destruction Function
        ~Numbered (void) =default;
        
        // Ternary Operator
        Numbered& operator= (const Numbered<R, T>&) =default;
        Numbered& operator= (Numbered<R, T>&&)      =delete;
        
    };
    

    //(    gd::Alternative Lamination for Lamination    )//
    template <typename... As>
    struct Alternative{
        
        //+    Static Value    +//
        public : 
        static constexpr Shadow<As...> shadows{ };
       

        //+    Static Functions    +//
        public : 
        static constexpr uint16_t depth (Empty =_key_) noexcept;
        static constexpr size_t   size  (Empty =_key_) noexcept;
        static constexpr size_t   width (Empty =_key_) noexcept;
        
        
        //+    Alias    +//
        template <uint16_t R>
        using Number = Numbered<R, decltype(Shadow<As...>::template type<R>())>;

 
        //+    Member Variables    +//
        protected : 
        uint16_t _number;
        uint8_t  _element[width(_key_)];

       
        //+    Member Functions    +//
        public :
        // Construction Function
             Alternative (void)                      noexcept;
             Alternative (const Alternative<As...>&) noexcept;
             Alternative (Alternative<As...>&&)      noexcept;
        template <uint16_t R>
             Alternative (Number<R>)                 noexcept;
        auto construct   (void)                      noexcept -> Alternative<As...>&;
        auto construct   (const Alternative<As...>&) noexcept -> Alternative<As...>&;
        auto construct   (Alternative<As...>&&)      noexcept -> Alternative<As...>&;
        template <uint16_t R>
        auto construct   (Number<R>)                 noexcept -> Alternative<As...>&;
        template <uint16_t R>
        auto construct   (void)                      noexcept -> Alternative<As...>&;
        template <uint16_t R, typename U>
        auto construct   (const U&)                  noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, Alternative<As...>&>;
        template <uint16_t R, typename U>
        auto construct   (U&&)                       noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, Alternative<As...>&>;
        

        // Destruction Function
                            ~Alternative (void)    noexcept;
        template <uint16_t R>
        Alternative<As...>&  destruct    (void)    noexcept;
        template <uint16_t R>
        Alternative<As...>& _destruct    (Rank<R>) noexcept;
        Alternative<As...>& _destruct    (Rank<0>) noexcept;
        
        // Reference Functions
        uint16_t                   number     (void)   const noexcept;
        template <uint16_t R>
              auto                 ref        (void)   const noexcept -> const decltype(Shadow<As...>::template type<R>())&;
        const Alternative<As...>*  spec       (void)   const noexcept;
        const Alternative<As...>&  operator() (size_t) const noexcept;

        // Access Functions
        template <uint16_t R>
        auto                 path       (void)   noexcept  -> const decltype(Shadow<As...>::template type<R>())&;
        Alternative<As...>*  data       (void)   noexcept;
        Alternative<As...>&  operator[] (size_t) noexcept;
        
        // Ternary Operator
        Alternative<As...>& operator= (const Alternative<As...>&) noexcept;
        Alternative<As...>& operator= (Alternative<As...>&&)      noexcept;
        template <uint16_t R>
        Alternative<As...>& operator= (Number<R>)                 noexcept;
               
    };
    
    

    //(    gd::ElasticAlternative Lamination for Lamination    )//
    template <typename... As>
    struct ElasticAlternative{
         
        //+    Static Value    +//
        public : 
        static constexpr Shadow<As...> shadows{ };
       

        //+    Static Functions    +//
        public : 
        static constexpr uint16_t depth (Empty =_key_) noexcept;
        static constexpr size_t   size  (Empty =_key_) noexcept;
        static constexpr size_t   width (Empty =_key_) noexcept;
        
        
        //+    Alias    +//
        template <uint16_t R>
        using Number = Numbered<R, decltype(Shadow<As...>::template type<R>())>;

 
        //+    Member Variables    +//
        protected : 
        uint16_t _number;
        uint8_t  _element[width(_key_)];

       
        //+    Member Functions    +//
        public :
        // Construction Function
              ElasticAlternative (void)                                      noexcept;
              ElasticAlternative (const ElasticAlternative<As...>&)          noexcept;
              ElasticAlternative (ElasticAlternative<As...>&&)               noexcept;
        template <uint16_t R>
              ElasticAlternative (Number<R>)                                 noexcept;
        auto  construct          (void)                                      noexcept -> ElasticAlternative<As...>&;
        auto  construct          (const ElasticAlternative<As...>&)          noexcept -> ElasticAlternative<As...>&;
        template <uint16_t R>
        auto _construct          (Rank<R>, const ElasticAlternative<As...>&) noexcept -> void;
        auto _construct          (Rank<0>, const ElasticAlternative<As...>&) noexcept -> void;
        auto  construct          (ElasticAlternative<As...>&&)               noexcept -> ElasticAlternative<As...>&;
        template <uint16_t R>
        auto _construct          (Rank<R>, ElasticAlternative<As...>&&)      noexcept -> void;
        auto _construct          (Rank<0>, ElasticAlternative<As...>&&)      noexcept -> void;
        template <uint16_t R>
        auto  construct          (void)                                      noexcept -> ElasticAlternative<As...>&;
        template <uint16_t R, typename U>
        auto _construct          (void)                                      noexcept -> void;
        template <uint16_t R, typename U>
        auto  construct          (const U&)                                  noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, ElasticAlternative<As...>&>;
        template <uint16_t R, typename U>
        auto  construct          (U&&)                                       noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, ElasticAlternative<As...>&>;
        template <uint16_t R>
        auto  construct          (Number<R>)                                 noexcept -> ElasticAlternative<As...>&;
        

        // Destruction Function
                                   ~ElasticAlternative (void)    noexcept;
        ElasticAlternative<As...>&  destruct           (void)    noexcept;
        template <uint16_t R>
        void                       _destruct           (Rank<R>) noexcept;
        void                       _destruct           (Rank<0>) noexcept;
        template <uint16_t R, typename U>
        void                       _destruct           (void)    noexcept;
        
        // Reference Functions
        uint16_t                          number     (void)   const noexcept;
        template<uint16_t R>
              auto                        ref        (void)   const noexcept -> const decltype(Shadow<As...>::template type<R>())&;
        const ElasticAlternative<As...>*  spec       (void)   const noexcept;
        const ElasticAlternative<As...>&  operator() (size_t) const noexcept;

        // Access Functions
        template<uint16_t R>
        auto                        path       (void)   noexcept -> decltype(Shadow<As...>::template type<R>())&;
        ElasticAlternative<As...>*  data       (void)   noexcept;
        ElasticAlternative<As...>&  operator[] (size_t) noexcept;

        // Ternary Operator
        ElasticAlternative<As...>&  operator=      (const ElasticAlternative<As...>&)          noexcept;
        template <uint16_t R>
        void                       _operator_equal (Rank<R>, const ElasticAlternative<As...>&) noexcept;
        void                       _operator_equal (Rank<0>, const ElasticAlternative<As...>&) noexcept;
        ElasticAlternative<As...>&  operator=      (ElasticAlternative<As...>&&)               noexcept;
        template <uint16_t R>
        void                       _operator_equal (Rank<R>, ElasticAlternative<As...>&&)      noexcept;
        void                       _operator_equal (Rank<0>, ElasticAlternative<As...>&&)      noexcept;
        template <uint16_t R>
        ElasticAlternative<As...>&  operator=      (Number<R>)                                 noexcept;

    };
    

    
    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename... As>
    std::ostream&  operator<<          (std::ostream&, const gd::Alternative<As...>&)                 noexcept;
    template <uint16_t R, typename... As>
    void          _operator_left_shift (Rank<R>, std::ostream&, const gd::Alternative<As...>&)        noexcept;
    template <typename... As>
    void          _operator_left_shift (Rank<0>, std::ostream&, const gd::Alternative<As...>&)        noexcept;
    template <typename... As>
    std::ostream&  operator<<          (std::ostream&, const gd::ElasticAlternative<As...>&)          noexcept;
    template <uint16_t R, typename... As>
    void          _operator_left_shift (Rank<R>, std::ostream&, const gd::ElasticAlternative<As...>&) noexcept;
    template <typename... As>
    void          _operator_left_shift (Rank<0>, std::ostream&, const gd::ElasticAlternative<As...>&) noexcept;

    
}



//++++++++++++++++++++++++++//
//    Inline Definitions    //
//++++++++++++++++++++++++++//
#include "alternative.inl"

#endif
