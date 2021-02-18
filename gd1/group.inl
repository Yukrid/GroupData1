#ifndef GROUPDATA_GROUP_INL
#define GROUPDATA_GROUP_INL

#include "./group.hpp"
#include <cstring>

namespace gd{

    //+++++++++++++++++++++//
    //    Group Classes    //
    //+++++++++++++++++++++//
    //(    gd::Group<T,D> Structure Tempalte for Structure    )//
    //+    Static Functions    +//
    template <typename T, uint16_t D>
    constexpr uint16_t Group<T,D>::depth(Empty) noexcept
    {
        return D;   
    }
    
    
    template <typename T, uint16_t D>
    constexpr size_t Group<T,D>::size(Empty) noexcept
    {
        return 1;   
    }

    
        
    //+    Member Functions    +//
    // Construcntion Functions
    template <typename T, uint16_t D>
    Group<T,D>::Group(void) noexcept
    {
        return;
    }
    
    
    template <typename T, uint16_t D>
    Group<T,D>::Group(const Group<T,D>& gr_) noexcept
    {
        std::memcpy(_elements, gr_._elements, sizeof(T)*D);
        
        return;
    }


    template <typename T, uint16_t D>
    Group<T,D>::Group(Group<T,D>&& gr_) noexcept
    {
        std::memcpy(_elements, gr_._elements, sizeof(T)*D);
        
        return;
    }
    
    
    template <typename T, uint16_t D>
    Group<T,D>::Group(std::initializer_list<T> lst_) noexcept
    {
        std::memcpy(_elements, lst_.begin(), sizeof(T)*(D>lst_.size() ? lst_.size() : D));
        for(size_t a=lst_.size(); a<D; ++a){
            std::memcpy(_elements+a, lst_.end()-1, sizeof(T));
        }
        
        return;
    }
    

    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::construct(void) noexcept
    {
        new(this) Group();

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::construct(const Group<T,D>& gr_) noexcept
    {
        new(this) Group(gr_);

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::construct(Group<T,D>&& gr_) noexcept
    {
        new(this) Group(std::move(gr_));

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::construct(std::initializer_list<T> lst_) noexcept
    {
        new(this) Group(lst_);

        return *this;
    }

    

    // Destruction Functions
    template <typename T, uint16_t D>
    Group<T,D>::~Group(void) noexcept
    {
        return;
    }
    
    
    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::destruct(void) noexcept
    {
        this->~Group();

        return *this;
    }



    // Reference functions
    template <typename T, uint16_t D> template<uint16_t N>
    auto Group<T,D>::path(void) const noexcept -> typename std::enable_if_t<(N<D), const T&>
    {
        return _elements[N];
    }

    
    #ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    const T& Group<T,D>::operator()(uint16_t id_) const
    {
        if(id_>=D) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::operator()(uint16_t)]", D, id_);
        
        return _elements[id_];
    }

    #else

    template <typename T, uint16_t D>
    const T& Group<T,D>::operator()(uint16_t id_) const noexcept
    { 
        return _elements[id_];
    }
    #endif
   
 
    template <typename T, uint16_t D>
    const Group<T,D>& Group<T,D>::operator[](const size_t& id_) const noexcept
    {
        #ifdef GROUPDATA_GROUP_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::operator[](const size_t&)]", id_);
        #endif
        return *this;
    }
   

    template <typename T, uint16_t D>
    const T* Group<T,D>::data(void) const noexcept
    { 
        return _elements;
    }
    
     
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    Range<const T> Group<T,D>::range(uint16_t e_) const
    {
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);

        return Range<const T>{_elements, _elements+e_};
    }

        
    template <typename T, uint16_t D>
    Range<const T> Group<T,D>::range(uint16_t b_, uint16_t e_) const
    {
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t, uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t, uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t, uint16_t)]", b_, e_);
        
        return Range<const T>{_elements+b_, _elements+e_};
    }
    
#else
     
    template <typename T, uint16_t D>
    Range<const T> Group<T,D>::range(uint16_t e_) const noexcept
    {
        return Range<const T>{_elements, _elements+e_};
    }

            
    template <typename T, uint16_t D>
    Range<const T> Group<T,D>::range(uint16_t b_, uint16_t e_) const noexcept
    {
        return Range<const T>{_elements+b_, _elements+e_};
    }
#endif
    

#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    const StaticDepthView<const T> Group<T,D>::view(uint16_t e_) const
    {
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t)]", D, e_);

        return StaticDepthView(e_, _elements);
    }

        
    template <typename T, uint16_t D>
    const StaticDepthView<const T> Group<T,D>::view(uint16_t b_, uint16_t e_) const
    {
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", b_, e_);
        
        return StaticDepthView(e_-b_, _elements+b_);
    }
    
#else
    
    template <typename T, uint16_t D>
    const StaticDepthView<const T> Group<T,D>::view(uint16_t e_) const noexcept
    {
        return StaticDepthView(e_, _elements);
    }

        
    template <typename T, uint16_t D>
    const StaticDepthView<const T> Group<T,D>::view(uint16_t b_, uint16_t e_) const noexcept
    {
        return StaticDepthView(e_-b_, _elements+b_);
    }
#endif



    // Access functions
    template <typename T, uint16_t D> template<uint16_t N>
    auto Group<T,D>::path(void) noexcept -> typename std::enable_if_t<(N<D), T&>
    {
        return _elements[N];
    }
    
        
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    T& Group<T,D>::operator()(uint16_t id_)
    {
        if(id_>=D) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::path(uint16_t)]", D, id_);
        
        return _elements[id_];
    }

#else

    template <typename T, uint16_t D>
    T& Group<T,D>::operator()(uint16_t id_) noexcept
    { 
           return _elements[id_];
    }

#endif 
 

    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator[](const size_t& id_) noexcept
    {
#ifdef GROUPDATA_GROUP_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::operator[](const size_t&)]", id_);
#endif

        return *this;
    }
   

    template <typename T, uint16_t D>
    T* Group<T,D>::data(void) noexcept
    { 
        return _elements;
    }
     
    
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    Range<T> Group<T,D>::range(uint16_t e_)
    {    
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);

        return Range<T>{_elements, _elements+e_};
    }


    template <typename T, uint16_t D>
    Range<T> Group<T,D>::range(uint16_t b_, uint16_t e_)
    {    
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", b_, e_);

        return Range<T>{_elements+b_, _elements+e_};
    }

#else

    template <typename T, uint16_t D>
    Range<T> Group<T,D>::range(uint16_t e_) noexcept
    {    
        return Range<T>{_elements, _elements+e_};
    }


    template <typename T, uint16_t D>
    Range<T> Group<T,D>::range(uint16_t b_, uint16_t e_) noexcept
    {    

        return Range<T>{_elements+b_, _elements+e_};
    }
#endif


#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    StaticDepthView<T> Group<T,D>::view(uint16_t e_)
    {
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t)]", D, e_);

        return StaticDepthView(e_, _elements);
    }

        
    template <typename T, uint16_t D>
    StaticDepthView<T> Group<T,D>::view(uint16_t b_, uint16_t e_)
    {
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::Group<"}+typeid(T).name()+", "+std::to_string(D)+">::view(uint16_t, uint16_t)]", b_, e_);
        
        return StaticDepthView(e_-b_, _elements+b_);
    }
    
#else
    
    template <typename T, uint16_t D>
    StaticDepthView<T> Group<T,D>::view(uint16_t e_) noexcept
    {
        return StaticDepthView(e_, _elements);
    }

        
    template <typename T, uint16_t D>
    StaticDepthView<T> Group<T,D>::view(uint16_t b_, uint16_t e_) noexcept
    {
        return StaticDepthView(e_-b_, _elements+b_);
    }
#endif
    


    // Binary Operator
    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(const Group<T,D>& gr_) noexcept
    {
        std::memcpy(_elements, gr_._elements, sizeof(T)*D);

        return *this;
    }
    
    
    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(Group<T,D>&& gr_) noexcept
    {
        std::memcpy(_elements, gr_._elements, sizeof(T)*D);

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(std::initializer_list<T> lst_) noexcept
    {
        std::memcpy(_elements, lst_.begin(), sizeof(T)*(D>lst_.size() ? lst_.size() : D));

        return *this;
    }

    
    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(const Range<T>& r_) noexcept
    {
        size_t rsz=(static_cast<size_t>(r_.end()-r_.begin()));
        std::memcpy(_elements, r_.begin(), sizeof(T)*(D>rsz ? rsz : D));

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(const Range<const T>& r_) noexcept
    {
        size_t rsz=(static_cast<size_t>(r_.end()-r_.begin()));
        std::memcpy(_elements, r_.begin(), sizeof(T)*(D>rsz ? rsz : D));

        return *this;
    }


    template <typename T, uint16_t D>
    Group<T,D>& Group<T,D>::operator=(const StaticDepthView<T>& sdv_) noexcept
    {
        std::memcpy(_elements, sdv_.data(), sizeof(T)*(D>sdv_.depth() ? sdv_.depth() : D));

        return *this;
    }
    


    // Casting Function
    template <typename T, uint16_t D> template <uint16_t E>
    Group<T,D>::operator Group<T,E>() const noexcept
    {
        Group<T,E> gr;
        std::memcpy(_elements, gr._elements, sizeof(T)*(D>E ? E : D));

        return gr;
    }


    template <typename T, uint16_t D> template <typename U, uint16_t E>
    Group<T,D>::operator Group<U,E>() const noexcept
    {
        Group<U,E> gr;
        for(uint16_t a=0; a<D && a<E; ++a){
            gr(a)=static_cast<U>(_elements[a]);
        }

        return gr;
    }


    /*
    //(    gd::ClassGroup<T,D> Structure Tempalte for Class    )//
    //+    Static Functions    +//
    template <typename T, uint16_t D>
    constexpr uint16_t ClassGroup<T,D>::depth(Empty) noexcept
    {
        return D;   
    }
    
    
    template <typename T, uint16_t D>
    constexpr size_t ClassGroup<T,D>::size(Empty) noexcept
    {
        return 1;   
    }

    
        
    //+    Member Functions    +//
    // Construcntion Functions
    template <typename T, uint16_t D>
    ClassGroup<T,D>::ClassGroup(void) noexcept
        : _elements ( )
    {
        return;
    }
    
    
    template <typename T, uint16_t D>
    ClassGroup<T,D>::ClassGroup(const ClassGroup<T,D>& gr_) noexcept
        : _elements ( )
    {
        for(uint16_t a=0; a<D; ++a){
            (_elements+a)->~T();
            new (_elements+a) T(gr_(a));
        }
        
        return;
    }


    template <typename T, uint16_t D>
    ClassGroup<T,D>::ClassGroup(ClassGroup<T,D>&& gr_) noexcept
        : _elements ( )
    {
        for(uint16_t a=0; a<D; ++a){
            (_elements+a)->~T();
            new (_elements+a) T(std::move(gr_(a)));
        }

        return;
    }
    
    
    template <typename T, uint16_t D>
    ClassGroup<T,D>::ClassGroup(std::initializer_list<T> lst_) noexcept
        : _elements ( )
    {
        for(uint16_t a=0; a<D && a<lst_.size(); ++a){
            (_elements+a)->~T();
            new (_elements+a) T{lst_.begin()[a]};
        }

        return;
    }
    

    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::construct(void) noexcept
    {
        new(this) ClassGroup();

        return *this;
    }


    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::construct(const ClassGroup<T,D>& gr_) noexcept
    {
        new(this) ClassGroup(gr_);

        return *this;
    }


    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::construct(ClassGroup<T,D>&& gr_) noexcept
    {
        new(this) ClassGroup(std::move(gr_));

        return *this;
    }


    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::construct(std::initializer_list<T> lst_) noexcept
    {
        new(this) ClassGroup(lst_);

        return *this;
    }
    
    

    // Destruction Functions
    template <typename T, uint16_t D>
    ClassGroup<T,D>::~ClassGroup(void) noexcept
    {
        return;
    }
    
    
    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::destruct(void) noexcept
    {
        this->~ClassGroup();

        return *this;
    }



    // Reference functions
    template <typename T, uint16_t D> template<uint16_t N>
    auto ClassGroup<T,D>::path(void) const noexcept -> typename std::enable_if_t<(N<D), const T&>
    {
        return _elements[N];
    }

    
    #ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    const T& ClassGroup<T,D>::operator()(uint16_t id_) const
    {
        if(id_>=D) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::operator()(uint16_t)]", D, id_);
        
        return _elements[id_];
    }

    #else

    template <typename T, uint16_t D>
    const T& ClassGroup<T,D>::operator()(uint16_t id_) const noexcept
    { 
        return _elements[id_];
    }
    #endif
   
    
    template <typename T, uint16_t D>
    const ClassGroup<T,D>* ClassGroup<T,D>::data(void) const noexcept
    { 
        return this;
    }
    
    
    template <typename T, uint16_t D>
    const ClassGroup<T,D>& ClassGroup<T,D>::operator[](const size_t& id_) const noexcept
    {
        #ifdef GROUPDATA_GROUP_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::operator[](const size_t&)]", id_);
        #endif
        return *this;
    }
    
     
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    Range<const T> ClassGroup<T,D>::range(uint16_t e_) const
    {
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);

        return Range<const T>{_elements, _elements+e_};
    }

        
    template <typename T, uint16_t D>
    Range<const T> ClassGroup<T,D>::range(uint16_t b_, uint16_t e_) const
    {
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", b_, e_);
        
        return Range<const T>{_elements+b_, _elements+e_};
    }
    
#else
    
    template <typename T, uint16_t D>
    Range<const T> ClassGroup<T,D>::range(uint16_t e_) const noexcept
    {
        return Range<const T>{_elements, _elements+e_};
    }

        
    template <typename T, uint16_t D>
    Range<const T> ClassGroup<T,D>::range(uint16_t b_, uint16_t e_) const noexcept
    {
        return Range<const T>{_elements+b_, _elements+e_};
    }
#endif



    // Access functions
    template <typename T, uint16_t D> template<uint16_t N>
    auto ClassGroup<T,D>::path(void) noexcept -> typename std::enable_if_t<(N<D), T&>
    {
        return _elements[N];
    }
    
        
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    T& ClassGroup<T,D>::operator()(uint16_t id_)
    {
        if(id_>=D) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::path(uint16_t)]", D, id_);
        
        return _elements[id_];
    }

#else

    template <typename T, uint16_t D>
    T& ClassGroup<T,D>::operator()(uint16_t id_) noexcept
    { 
           return _elements[id_];
    }

#endif 
    
    template <typename T, uint16_t D>
    ClassGroup<T,D>* ClassGroup<T,D>::data(void) noexcept
    { 
        return this;
    }
    

    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::operator[](const size_t& id_) noexcept
    {
#ifdef GROUPDATA_GROUP_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::operator[](const size_t&)]", id_);
#endif

        return *this;
    }
    
    
#ifdef GROUPDATA_GROUP_EXCEPTION
    template <typename T, uint16_t D>
    Range<T> ClassGroup<T,D>::range(uint16_t e_)
    {    
        if(e_>D) throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);

        return Range<T>{_elements, _elements+e_};
    }


    template <typename T, uint16_t D>
    Range<T> ClassGroup<T,D>::range(uint16_t b_, uint16_t e_)
    {    
        if(b_>D)  throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, b_);
        if(e_>D)  throw exception::generation_of_over_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", D, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::ClassGroup<"}+typeid(T).name()+", "+std::to_string(D)+">::range(uint16_t)]", b_, e_);

        return Range<T>{_elements+b_, _elements+e_};
    }

#else

    template <typename T, uint16_t D>
    Range<T> ClassGroup<T,D>::range(uint16_t e_) noexcept
    {    
        return Range<T>{_elements, _elements+e_};
    }


    template <typename T, uint16_t D>
    Range<T> ClassGroup<T,D>::range(uint16_t b_, uint16_t e_) noexcept
    {    

        return Range<T>{_elements+b_, _elements+e_};
    }
#endif



    // Binary Operator
    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::operator=(const ClassGroup<T,D>& gr_) noexcept
    {   
        for(uint16_t a=0; a<D; ++a){
            _elements[a]=gr_(a);
        }

        return *this;
    }
    
    
    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::operator=(ClassGroup<T,D>&& gr_) noexcept
    {
        for(uint16_t a=0; a<D; ++a){
            _elements[a]=std::move(gr_(a));
        }

        return *this;
    }


    template <typename T, uint16_t D>
    ClassGroup<T,D>& ClassGroup<T,D>::operator=(std::initializer_list<T> lst_) noexcept
    {
        for(uint16_t a=0; a<D && a<lst_.size(); ++a){
            _elements[a]=lst_.begin()[a];
        }

        return *this;
    }



    // Casting Function
    template <typename T, uint16_t D> template <typename U, uint16_t E>
    ClassGroup<T,D>::operator ClassGroup<U,E>() const noexcept
    {
        ClassGroup<U,E> gr;
        for(size_t a=0; a<D && a<E; ++a){
            gr(a)=_elements[a];
        }
        for(size_t a=D; a<E; ++a){
            gr(a)=_elements[D-1];
        }

        return std::move(gr);
    }

    */



    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename T, uint16_t D>
    std::ostream& operator<<(std::ostream& os_, const gd::Group<T,D>& gr_) noexcept
    {
        for(const T& g : gr_.range()){
            gd::ostream(g, os_);
            os_<<" ";
        }
 
        return os_;
    }
    
  /*
    template <typename T, uint16_t D>
    std::ostream& operator<<(std::ostream& os_, const gd::ClassGroup<T,D>& gr_) noexcept
    {
        for(const T& g : gr_.range()){
            gd::ostream(g, os_);
            os_<<" ";
        }
 
        return os_;
    }
    */
}
#endif
