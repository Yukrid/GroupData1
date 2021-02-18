#ifndef GROUPDATA_GROUPDATA_HPP
#define GROUPDATA_GROUPDATA_HPP

#include <iostream>

namespace gd{

    //+++++++++++++++++++//
    //    Common Type    //
    //+++++++++++++++++++//
    //->   groupdata.hpp    <-//
    //(    gd::Empty Void    )//
    struct Empty{

    };


    //(    gd::Rank Void Template    )//
    template <uint16_t R>
    struct Rank{

    };
    
    
    //(    gd::Shadow Void Template    )//
    template <typename... As>
    struct Shadow{
        
        // Static Function
        template <uint16_t R>
        static constexpr void    type  (void);
        static constexpr void   _type  (void);
        static constexpr size_t  width (void);
    };
    

    //(    gd::Shadow<T, As...> Lamination Template    )//
    template <typename T, typename... As>
    struct Shadow<T, As...>{
        
        // Static Variable
        static constexpr Shadow<As...> shadows{ };
        
        // Static Function
        template <uint16_t R>
        static constexpr auto   _type  (Rank<R>)     -> decltype(Shadow<As...>::_type(std::declval<Rank<R-1>>()));
        static constexpr auto   _type  (Rank<0>)     -> T;
        template <uint16_t R>
        static constexpr auto    type  (void)    -> decltype(_type(std::declval<Rank<R>>()));
        static constexpr size_t  width (void);
        static constexpr size_t _width (void);
    };


   

    //(    gd::Range Lamination Template for Any    +//
    template <typename T>
    class Range{
        
        //+    Member Variables    +//
        T* _begin;
        T* _end;
 
        //+    Member Functions    +//
        public :
        // Construction Function
        Range (void)         =delete;
        Range (T*, T*)        noexcept;
        Range (const Range&) =delete;
        Range (Range&&)      =delete;

        // Access Function
        Range& operator= (const Range&) =delete;
        Range& operator= (Range&&)      =delete;
        T*     begin     (void)          noexcept;
        T*     end       (void)          noexcept;
    };
    
    
    
    //(    gd::ConstRange Lamination Template for Any    +//
    template <typename T>
    class ConstRange{
        
        //+    Member Variables    +//
        const T* _begin;
        const T* _end;

 
        //+    Member Functions    +//
        public :
        // Construction Function
        ConstRange (void)               =delete;
        ConstRange (const T*, const T*)  noexcept;
        ConstRange (const ConstRange&)  =delete;
        ConstRange (ConstRange&&)       =delete;

        // Access Function
              ConstRange& operator= (const ConstRange&) =delete;
              ConstRange& operator= (ConstRange&&)      =delete;
        const T*          begin     (void)               noexcept;
        const T*          end       (void)               noexcept;
    };




    //++++++++++++++++++++//
    //    Common Value    //
    //++++++++++++++++++++//
    //->    groupdata.hpp    <-//
    constexpr Empty _key_;

    


    //+++++++++++++++++++++++//
    //    Common Variable    //
    //+++++++++++++++++++++++//
    //->    groupdata.hpp groupdata.cpp    <-//
    extern size_t _format_length_;

    


    //++++++++++++++++++++++++//
    //    Common Functions    //
    //++++++++++++++++++++++++//
    //->     groupdata.hpp groupdata.inl    <-//
    //+    std::ostream.operator    +//
    template <typename T>
    auto _ostream(const T&, std::ostream&, int32_t) noexcept -> decltype(void(std::declval<std::ostream&>()<<std::declval<T>()));

    template <typename T>
    auto _ostream(const T&, std::ostream&, int16_t) noexcept -> void;

    template <typename T>
    auto ostream(const T&, std::ostream&)           noexcept -> decltype(void(_ostream(std::declval<T>(), std::declval<std::ostream&>(), 0)));

    //+    gd::[Object].depth    +//
    template <typename T>
    constexpr auto _depth(const T&, uint16_t, int32_t) noexcept -> decltype(std::declval<T>().depth(_key_));
    
    template <typename T>
    constexpr auto _depth(const T&, uint16_t, int16_t) noexcept -> int16_t;
    
    template <typename T>
    constexpr auto depth(const T&, uint16_t)           noexcept-> decltype(_depth(std::declval<T>(), std::declval<uint16_t>(), 0));

    


    //+++++++++++++++++++++++++++//
    //    Forward Decleration    //
    //+++++++++++++++++++++++++++//    
    // Basic
    //->    group.hpp, group.inl    <-//
    template <typename T, uint16_t D>   struct Group;
    //->    tag.hpp, tag.inl    <-//
    template <uint16_t D>               struct Tag;
    //->    tuple.hpp, tuple.inl    <-//
    template <typename... As>           struct Tuple;
    //->    alternative.hpp, alternative.inl    <-//
    template <typename... As>           struct Alternative;
    //->    array.hpp, array.inl    <-//
    template <size_t S, typename T>     struct Array;
    //->    vector.hpp, vector.inl    <-//
    template <size_t S, typename T>     struct Vector;
    //->    list.hpp, list.inl    <-//
    template <typename T>               struct List;
    //->    view.hpp, view.inl    <-//
    template <typename T>               struct View;
    //->    bridge.hpp, bridge.inl    <-//
    template <size_t S, typename... As> struct Bridge;
    //->    bundle.hpp, bundle.inl    <-//
    template <size_t S, typename... As> struct Bundle;
    //->    table.hpp, table.inl    <-//
    template <typename... As>           struct Table;


    // Elastic
    //->    group.hpp, group.inl    <-//
    template <typename T, uint16_t D>   struct ElasticGroup;
    //->    tuple.hpp, tuple.inl    <-//
    template <typename... As>           struct ElasticTuple;
    //->    alternative.hpp, alternative.inl    <-//
    template <typename... As>           struct ElasticAlternative;
    //->    array.hpp, array.inl    <-//
    template <size_t S, typename T>     struct ElasticArray;
    //->    vector.hpp, vector.inl    <-//
    template <size_t S, typename T>     struct ElasticVector;
    //->    list.hpp, list.inl    <-//
    template <typename T>               struct ElasticList;
    //->    view.hpp, view.inl    <-//
    template <typename T>               struct ElasticView;
    //->    bridge.hpp, bridge.inl    <-//
    template <size_t S, typename... As> struct ElasticBridge;
    //->    bundle.hpp, bundle.inl    <-//
    template <size_t S, typename... As> struct ElasticBundle;
    //->    table.hpp, table.inl    <-//
    template <typename... As>           struct ElasticTable;
}




//++++++++++++++++++++++++++//
//    Inline Definitions    //
//++++++++++++++++++++++++++//
#include "groupdata.inl"

#endif
