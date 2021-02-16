#ifndef GROUPDATA_ALTERNATIVE_INL
#define GROUPDATA_ALTERNATIVE_INL

#include "alternative.hpp"
#include <climits>
#include <cstring>

namespace gd{

    //+++++++++++++++++++++//
    //    Group Objects    //
    //+++++++++++++++++++++//
    //(    gd::Numberd for Lamination    )//
    //+    Member Functions    +//
    template <uint16_t R, typename T>
    Numbered<R, T>::Numbered (void) noexcept
        : value { }
    {
        return;
    }


    template <uint16_t R, typename T>
    Numbered<R, T>::Numbered (const T& t_) noexcept
        : value {t_}
    {
        return;
    }
    
    
    template <uint16_t R, typename T>
    Numbered<R, T>::Numbered (T&& t_) noexcept
        : value {std::move(t_)}
    {
        return;
    }

    
    

    

    //(    gd::Alternative Lamination for Lamination    )//
    //+    Static Functions    +//
    template <typename... As>
    inline constexpr uint16_t Alternative<As...>::depth (Empty) noexcept
    {
        return 1;
    }


    template <typename... As>
    inline constexpr size_t Alternative<As...>::size (Empty) noexcept
    {
        return 1;
    }
    
    
    template <typename... As>
    inline constexpr size_t Alternative<As...>::width (Empty) noexcept
    {
        return shadows.width();
    }
    

    
    //+    Member Functions    +//
    // Constructon Functions
    template <typename... As>
    Alternative<As...>::Alternative(void) noexcept
        : _number {0}
    { 
        return;
    }
    
    
    template <typename... As>
    Alternative<As...>::Alternative(const Alternative<As...>& al_) noexcept
    {
        std::memcpy(this, &al_, sizeof *this);
        
        return;
    }
    
    
    template <typename... As>
    Alternative<As...>::Alternative(Alternative<As...>&& al_) noexcept
    {
        std::memcpy(this, &al_, sizeof *this);
        
        return;
    }
    
    
    template <typename... As> template <uint16_t R>
    Alternative<As...>::Alternative(Numbered<R, decltype(Shadow<As...>::template type<R>())> n_) noexcept
        : _number {R}
    {
        std::memcpy(_element, &n_.value, sizeof n_.value);
    
        return;
    }
    
    
    template <typename... As>
    auto Alternative<As...>::construct(void) noexcept -> Alternative<As...>&
    {
        new(this) Alternative();

        return *this;
    }
    

    template <typename... As>
    auto Alternative<As...>::construct(const Alternative<As...>& al_) noexcept -> Alternative<As...>&
    {
        new(this) Alternative(al_);

        return *this;
    }


    template <typename... As>
    auto Alternative<As...>::construct(Alternative<As...>&& al_) noexcept -> Alternative<As...>&
    {
        new(this) Alternative(al_);

        return *this;
    }
 
 
    template <typename... As> template <uint16_t R>
    auto Alternative<As...>::construct(Numbered<R, decltype(Shadow<As...>::template type<R>())> n_) noexcept -> Alternative<As...>&
    {
        _number=R;
        std::memcpy(_element, &n_.value, sizeof n_.value);

        return *this;
    }
    
     
    template <typename... As> template <uint16_t R>
    auto Alternative<As...>::construct(void) noexcept -> Alternative<As...>&
    {
        _number=R;

        return *this;
    }
   
    
    template <typename... As> template <uint16_t R, typename U>
    auto Alternative<As...>::construct(const U& u_) noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, Alternative<As...>&>
    {
        _number=R;
        std::memcpy(_element, &u_, sizeof u_);

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R, typename U>
    auto Alternative<As...>::construct(U&& u_) noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, Alternative<As...>&>
    {
        _number=R;
        std::memcpy(_element, &u_, sizeof u_);

        return *this;
    }

   

    // Destructon Functions
    template <typename... As>
    Alternative<As...>::~Alternative(void) noexcept
    {   
        return;
    }


    template <typename... As> template<uint16_t N>
    Alternative<As...>& Alternative<As...>::destruct(void) noexcept
    {
        ~Alternative();

        return *this;
    }



    // Reference Functions
    template <typename... As>
    uint16_t Alternative<As...>::number(void) const noexcept
    {
        return _number;
    }


    template <typename... As> template <uint16_t R>
    auto Alternative<As...>::ref(void) const noexcept -> const decltype(Shadow<As...>::template type<R>())&
    {
        return *reinterpret_cast<const decltype(Shadow<As...>::template type<R>())*>(_element);
    }


    template <typename... As>
    const Alternative<As...>* Alternative<As...>::spec(void) const noexcept
    {
        return this;
    }


    template <typename... As>
    const Alternative<As...>& Alternative<As...>::operator()(size_t) const noexcept
    {
        return *this;
    }

    
   
    // Access Functions
    template <typename... As> template <uint16_t R>
    auto Alternative<As...>::path(void) noexcept -> const decltype(Shadow<As...>::template type<R>())&
    {
        return *reinterpret_cast<const decltype(Shadow<As...>::template type<R>())*>(_element);
    }
    
    
    template <typename... As>
    Alternative<As...>* Alternative<As...>::data(void) noexcept
    {
        return this;
    }


    template <typename... As>
    Alternative<As...>& Alternative<As...>::operator[](size_t) noexcept
    {
        return *this;
    }    



    // Ternary Operator
    template <typename... As>
    Alternative<As...>& Alternative<As...>::operator= (const Alternative<As...>& al_) noexcept
    {
        std::memcpy(this, &al_, sizeof *this);
        
        return *this;
    }
    

    template <typename... As>
    Alternative<As...>& Alternative<As...>::operator= (Alternative<As...>&& al_) noexcept
    {
        std::memcpy(this, &al_, sizeof *this);
        
        return *this;
    }
    
    
    
    template <typename... As> template <uint16_t R>
    Alternative<As...>& Alternative<As...>::operator= (Numbered<R, decltype(Shadow<As...>::template type<R>())> n_) noexcept
    {
        _number=R;
        std::memcpy(_element, &n_.value, sizeof n_.value);
        
        return *this;
    }


    
    

    //(    gd::ElasticAlternative Lamination for Lamination    )//
    //+    Static Functions    +//
    template <typename... As>
    inline constexpr uint16_t ElasticAlternative<As...>::depth (Empty) noexcept
    {
        return 1;
    }


    template <typename... As>
    inline constexpr size_t ElasticAlternative<As...>::size (Empty) noexcept
    {
        return 1;
    }
    
    
    template <typename... As>
    inline constexpr size_t ElasticAlternative<As...>::width (Empty) noexcept
    {
        return shadows.width();
    }
    

    
    //+    Member Functions    +//
    // Constructon Functions
    template <typename... As>
    ElasticAlternative<As...>::ElasticAlternative(void) noexcept
        : _number {0}
    { 
        _construct<0, decltype(Shadow<As...>::template type<0>())>();

        return;
    }
    
    
    template <typename... As>
    ElasticAlternative<As...>::ElasticAlternative(const ElasticAlternative<As...>& al_) noexcept
        : _number {al_.number()}
    {
        _construct(Rank<sizeof...(As)-1>{}, al_);

        return;
    }
    
    
    template <typename... As>
    ElasticAlternative<As...>::ElasticAlternative(ElasticAlternative<As...>&& al_) noexcept
        : _number {al_.number()}
    {
        _construct(Rank<sizeof...(As)-1>{}, std::move(al_));

        return;
    }
    
    
    template <typename... As> template <uint16_t R>
    ElasticAlternative<As...>::ElasticAlternative(Number<R> n_) noexcept
        : _number {R}
    {
        construct<R>(std::move(n_.value));

        return;
    }
    
   
    template <typename... As>
    auto ElasticAlternative<As...>::construct(void) noexcept -> ElasticAlternative<As...>&
    {
        _number=0;
        _construct<0, decltype(Shadow<As...>::template type<0>())>();

        return *this;
    }
    
    
    template <typename... As>
    auto ElasticAlternative<As...>::construct(const ElasticAlternative<As...>& al_) noexcept -> ElasticAlternative<As...>&
    {
        _number=al_.number();
        _construct(Rank<sizeof...(As)-1>{}, al_);

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R>
    auto ElasticAlternative<As...>::_construct(Rank<R>, const ElasticAlternative<As...>& al_) noexcept -> void
    {
        if(R==al_.number()){
            _construct<R>(al_.ref<R>());
        }
        _construct(Rank<R-1>{}, al_);

        return;
    }


    template <typename... As>
    auto ElasticAlternative<As...>::_construct(Rank<0>, const ElasticAlternative<As...>& al_) noexcept -> void
    {
        if(0==al_.number()){
            _construct<0>(al_.ref<0>());
        }

        return;
    }
    
    
    template <typename... As>
    auto ElasticAlternative<As...>::construct(ElasticAlternative<As...>&& al_) noexcept -> ElasticAlternative<As...>&
    {
        _number=al_.number();
        _construct(Rank<sizeof...(As)-1>{}, std::move(al_));

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R>
    auto ElasticAlternative<As...>::_construct(Rank<R>, ElasticAlternative<As...>&& al_) noexcept -> void
    {
        if(R==al_.number()){
            _construct<R>(std::move(al_.ref<R>()));
        }
        _construct(Rank<R-1>{}, std::move(al_));

        return;
    }


    template <typename... As>
    auto ElasticAlternative<As...>::_construct(Rank<0>, ElasticAlternative<As...>&& al_) noexcept -> void
    {
        if(0==al_.number()){
            _construct<0>(std::move(al_.ref<0>()));
        }

        return;
    }


    template <typename... As> template <uint16_t R>
    auto ElasticAlternative<As...>::construct(void) noexcept -> ElasticAlternative<As...>&
    {
        _number=R;
        _construct<R, decltype(Shadow<As...>::template type<R>())>();

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R, typename U>
    auto ElasticAlternative<As...>::_construct(void) noexcept -> void
    {
        new(reinterpret_cast<U*>(_element)) U{ };

        return;
    }
    

    template <typename... As> template <uint16_t R, typename U>
    auto ElasticAlternative<As...>::construct(const U& u_) noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, ElasticAlternative<As...>&>
    {
        _number=R;
        new(reinterpret_cast<U*>(_element)) U{u_};

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R, typename U>
    auto ElasticAlternative<As...>::construct(U&& u_) noexcept -> std::enable_if_t<std::is_same_v<decltype(Shadow<As...>::template type<R>()), U>, ElasticAlternative<As...>&>
    {
        _number=R;
        new(reinterpret_cast<U*>(_element)) U{std::move(u_)};

        return *this;
    }
    

    
    // Destructon Functions
    template <typename... As>
    ElasticAlternative<As...>::~ElasticAlternative(void) noexcept
    {
        destruct();

        return;
    }


    template <typename... As>
    ElasticAlternative<As...>& ElasticAlternative<As...>::destruct(void) noexcept
    {
        _destruct(Rank<sizeof...(As)-1>{ });

        return *this;
    }
    
    
    template <typename... As> template <uint16_t R>
    void ElasticAlternative<As...>::_destruct(Rank<R>) noexcept
    {
        if(R==_number){
            
            _destruct<R, decltype(Shadow<As...>::template type<R>())>();
            return;

        }else{
            
            _destruct(Rank<R-1>{ });
        }
    }
    
    
    template <typename... As>
    void ElasticAlternative<As...>::_destruct(Rank<0>) noexcept
    {
        if(0==_number){

            _destruct<0, decltype(Shadow<As...>::template type<0>())>();
        }

        return;
    }
    
    
    template <typename... As> template <uint16_t R, typename U>
    void ElasticAlternative<As...>::_destruct(void) noexcept
    {
        reinterpret_cast<U*>(_element)->~U();

        return;
    }



    // Reference Functions
    template <typename... As>
    uint16_t ElasticAlternative<As...>::number(void) const noexcept
    {
        return _number;
    }


    template <typename... As> template <uint16_t R>
    auto ElasticAlternative<As...>::ref(void) const noexcept -> const decltype(Shadow<As...>::template type<R>())&
    {
        return *reinterpret_cast<const decltype(Shadow<As...>::template type<R>())*>(_element);
    }


    template <typename... As>
    const ElasticAlternative<As...>* ElasticAlternative<As...>::spec(void) const noexcept
    {
        return this;
    }


    template <typename... As>
    const ElasticAlternative<As...>& ElasticAlternative<As...>::operator()(size_t) const noexcept
    {
        return *this;
    }

    
   
    // Access Functions
    template <typename... As> template <uint16_t R>
    auto ElasticAlternative<As...>::path(void) noexcept -> decltype(Shadow<As...>::template type<R>())&
    {
        return *reinterpret_cast<decltype(Shadow<As...>::template type<R>())*>(_element);
    }
    
    
    template <typename... As>
    ElasticAlternative<As...>* ElasticAlternative<As...>::data(void) noexcept
    {
        return this;
    }


    template <typename... As>
    ElasticAlternative<As...>& ElasticAlternative<As...>::operator[](size_t) noexcept
    {
        return *this;
    }
    
    

    // Ternary Operator
    template <typename... As>
    ElasticAlternative<As...>& ElasticAlternative<As...>::operator= (const ElasticAlternative<As...>& al_) noexcept
    {
        _operator_equal(Rank<sizeof...(As)-1>{}, al_);
        
        return *this;
    }
    
    
    template <typename... As> template <uint16_t R>
    void ElasticAlternative<As...>::_operator_equal (Rank<R>, const ElasticAlternative<As...>& al_) noexcept
    {
        
        if(R==al_.number()){

            if(_number==al_.number()){
                
                path<R>()=al_.ref<R>();
            
            }else{
                
                destruct();
                new(this) ElasticAlternative<As...>{al_};
            }
            
            return;

        }else{

        }

        return;
    }




/*
        if(_number==al_.number()){
            
            *reinterpret_cast<decltype(Shadow<As...>::template type<R>())*>(_element)
        }else{

            destruct();
            new(this) ElasticAlternative<As...>{al_};
        }
*/
   
/*
    template <typename... As>
    ElasticAlternative<As...>& ElasticAlternative<As...>::operator= (ElasticAlternative<As...>&& al_) noexcept
    {
        destruct();
        new(this) ElasticAlternative<As...>{std::move(al_)};
        
        return *this;
    }
    
    
    template <typename... As> template <uint16_t R>
    ElasticAlternative<As...>& ElasticAlternative<As...>::operator= (Numbered<R, decltype(Shadow<As...>::template type<R>())> n_) noexcept
    {
        destruct();
        new(this) ElasticAlternative<As...>{}
        _number=R;
        std::memcpy(_element, &n_.value, sizeof n_.value);
        
        return *this;
    }
  */  
       
    
    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename... As>
    std::ostream& operator<<(std::ostream& os_, const gd::Alternative<As...>& al_) noexcept
    {
        _operator_left_shift(Rank<sizeof...(As)-1>{ }, os_, al_);

        return os_;    
    }
    
    
    template <uint16_t R, typename... As>
    void _operator_left_shift(Rank<R>, std::ostream& os_, const gd::Alternative<As...>& al_) noexcept
    {
        if(R==al_.number()){
            
            gd::ostream(al_.template ref<R>(), os_);
            os_<<" ";

            return;

        }else{
            _operator_left_shift(Rank<uint16_t(R-1)>{ }, os_, al_);
        }
    }
    
    
    template <typename... As>
    void _operator_left_shift(Rank<0>, std::ostream& os_, const gd::Alternative<As...>& al_) noexcept
    {
        if(0==al_.number()){
        
            gd::ostream(al_.template ref<0>(), os_);
            os_<<" ";
        }

        return;
    }


    template <typename... As>
    std::ostream& operator<<(std::ostream& os_, const gd::ElasticAlternative<As...>& al_) noexcept
    {
        _operator_left_shift(Rank<sizeof...(As)-1>{ }, os_, al_);

        return os_;    
    }
    
    
    template <uint16_t R, typename... As>
    void _operator_left_shift(Rank<R>, std::ostream& os_, const gd::ElasticAlternative<As...>& al_) noexcept
    {
        if(R==al_.number()){
            
            gd::ostream(al_.template ref<R>(), os_);
            os_<<" ";

            return;

        }else{
            _operator_left_shift(Rank<uint16_t(R-1)>{ }, os_, al_);
        }
    }
    
    
    template <typename... As>
    void _operator_left_shift(Rank<0>, std::ostream& os_, const gd::ElasticAlternative<As...>& al_) noexcept
    {
        if(0==al_.number()){
        
            gd::ostream(al_.template ref<0>(), os_);
            os_<<" ";
        }

        return;
    }
}

#endif
