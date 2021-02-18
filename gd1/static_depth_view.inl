#ifndef GROUPDATA_STATIC_DEPTH_VIEW_INL
#define GROUPDATA_STATIC_DEPTH_VIEW_INL

#include "static_depth_view.hpp"
#include <cstring>

namespace gd{

    //++++++++++++++++++++++++++++++//
    //    StaticDepthView Typess    //
    //++++++++++++++++++++++++++++++//
    //(    gd::StaticDepthView Structure Template for Structure    )//
    //+    Static Functions    +//
    template <typename T>
    constexpr size_t StaticDepthView<T>::size(Empty) noexcept
    {
        return 1;
    }
    
        


    //+    Member Functions    +//
    // Construcntion Functions
    template <typename T>
    StaticDepthView<T>::StaticDepthView(uint16_t dep_, T* ptr_) noexcept
        : _depth {dep_}
        , _ptr   {ptr_}
    {
        return;
    }
    


    // Reference Functions
    template <typename T>
    uint16_t StaticDepthView<T>::depth(Empty) const noexcept
    {
        return _depth;
    }


#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T> template <uint16_t N>
    const T& StaticDepthView<T>::path(void) const
    {
        if(N>=_depth) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::path<uint16_t>(void)]", _depth, N);
        
        return _ptr[N];
    }


    template <typename T>
    const T& StaticDepthView<T>::operator()(uint16_t id_) const
    {
        if(id_>=_depth) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::operator()(uint16_t)]", _depth, id_);
        
        return _ptr[id_];
    }

#else
    template <typename T> template <uint16_t N>
    const T& StaticDepthView<T>::path(void) const noexcept
    {
        return _ptr[N];
    }

    template <typename T>
    const T& StaticDepthView<T>::operator()(uint16_t id_) const noexcept
    {
        return _ptr[id_];
    }
#endif


    template <typename T>
    const StaticDepthView<const T>& StaticDepthView<T>::operator[](const size_t& id_) const noexcept
    {
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::operator[](const size_t&)]", id_);
    #endif

        return *this;
    }

    
    template <typename T>
    const T* StaticDepthView<T>::data(void) const noexcept
    { 
        return _ptr;
    }


    template <typename T>
    Range<const T> StaticDepthView<T>::range(void) const noexcept
    {
        return Range<T>{_ptr, _ptr+_depth};
    }


#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T>
    Range<const T> StaticDepthView<T>::range(uint16_t e_) const
    {
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t)]", _depth, e_);
        
        return Range<T>{_ptr, _ptr+e_};
    }


    template <typename T>
    Range<const T> StaticDepthView<T>::range(uint16_t b_, uint16_t e_) const
    {
        if(b_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", _depth, b_);
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", _depth, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", b_, e_);
        
        return Range<T>{_ptr+b_, _ptr+e_};
    }

#else

    template <typename T>
    Range<const T> StaticDepthView<T>::range(uint16_t e_) const noexcept
    {
        return Range<T>{_ptr, _ptr+e_};
    }


    template <typename T>
    Range<const T> StaticDepthView<T>::range(uint16_t b_, uint16_t e_) const noexcept
    {
        return Range<T>{_ptr+b_, _ptr+e_};
    }
#endif


    template <typename T>
    const StaticDepthView<const T> StaticDepthView<T>::view(void) const noexcept
    {
        return StaticDepthView(_depth, _ptr);
    }


#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T>
    const StaticDepthView<const T> StaticDepthView<T>::view(uint16_t e_) const
    {
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t)]", _depth, e_);
        
        return StaticDepthView(e_, _ptr);
    }


    template <typename T>
    const StaticDepthView<const T> StaticDepthView<T>::view(uint16_t b_, uint16_t e_) const
    {
        if(b_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", _depth, b_);
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", _depth, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", b_, e_);
        
        return StaticDepthView(e_-b_, _ptr+b_);
    }

#else

    template <typename T>
    const StaticDepthView<const T> StaticDepthView<T>::view(uint16_t e_) const noexcept
    {
        return StaticDepthView(e_, _ptr);
    }


    template <typename T>
    const StaticDepthView<const T> StaticDepthView<T>::view(uint16_t b_, uint16_t e_) const noexcept
    {
        return StaticDepthView(e_-b_, _ptr+b_);
    }
#endif



    // Access functions
#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T> template <uint16_t N>
    T& StaticDepthView<T>::path(void)
    {
        if(N>=_depth) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::path<uint16_t>(void)]", _depth, N);
        
        return _ptr[N];
    }


    template <typename T>
    T& StaticDepthView<T>::operator()(uint16_t id_)
    {
        if(id_>=_depth) throw exception::exceeded_capacity_in_depth_direction(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::operator()(uint16_t)]", _depth, id_);
        
        return _ptr[id_];
    }

#else
    template <typename T> template <uint16_t N>
    T& StaticDepthView<T>::path(void) noexcept
    {
        return _ptr[N];
    }


    template <typename T>
    T& StaticDepthView<T>::operator()(uint16_t id_)noexcept
    {
        return _ptr[id_];
    }
#endif
 

    template <typename T>
    StaticDepthView<T>& StaticDepthView<T>::operator[](const size_t& id_) noexcept
    {
    #ifdef GROUPDATA_STATIC_DEPTH_VIEW_WARNING
        if(id_>0) warning::ignored_size_index(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::operator[](const size_t&)]", id_);
    #endif

        return *this;
    }

    
    template <typename T>
    T* StaticDepthView<T>::data(void) noexcept
    { 
        return _ptr;
    }


    template <typename T>
    Range<T> StaticDepthView<T>::range(void) noexcept
    {
        return Range<T>{_ptr, _ptr+_depth};
    }


#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T>
    Range<T> StaticDepthView<T>::range(uint16_t e_)
    {
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t)]", _depth, e_);
        
        return Range<T>{_ptr, _ptr+e_};
    }


    template <typename T>
    Range<T> StaticDepthView<T>::range(uint16_t b_, uint16_t e_)
    {
        if(b_>_depth)  throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", _depth, b_);
        if(e_>_depth)  throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", _depth, e_);
        if(b_>e_) throw exception::generation_of_backward_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::range(uint16_t, uint16_t)]", b_, e_);
        
        return Range<T>{_ptr+b_, _ptr+e_};
    }

#else

    template <typename T>
    Range<T> StaticDepthView<T>::range(uint16_t e_) noexcept
    {
        return Range<T>{_ptr, _ptr+e_};
    }


    template <typename T>
    Range<T> StaticDepthView<T>::range(uint16_t b_, uint16_t e_) noexcept
    {
        return Range<T>{_ptr+b_, _ptr+e_};
    }
#endif


    template <typename T>
    StaticDepthView<T> StaticDepthView<T>::view(void) noexcept
    {
        return StaticDepthView(_depth, _ptr);
    }


#ifdef GROUPDATA_STATIC_DEPTH_VIEW_EXCEPTION
    template <typename T>
    StaticDepthView<T> StaticDepthView<T>::view(uint16_t e_)
    {
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t)]", _depth, e_);
        
        return StaticDepthView(e_, _ptr);
    }


    template <typename T>
    StaticDepthView<T> StaticDepthView<T>::view(uint16_t b_, uint16_t e_)
    {
        if(b_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", _depth, b_);
        if(e_>_depth) throw exception::generation_of_over_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", _depth, e_);
        if(b_>e_)     throw exception::generation_of_backward_range(std::string{"[gd::StaticDepthView<"}+typeid(T).name()+">::view(uint16_t, uint16_t)]", b_, e_);
        
        return StaticDepthView(e_-b_, _ptr+b_);
    }

#else

    template <typename T>
    StaticDepthView<T> StaticDepthView<T>::view(uint16_t e_)noexcept
    {
        return StaticDepthView(e_, _ptr);
    }


    template <typename T>
    StaticDepthView<T> StaticDepthView<T>::view(uint16_t b_, uint16_t e_) noexcept
    {
        return StaticDepthView(e_-b_, _ptr+b_);
    }
#endif



    // Binary Operators
    template <typename T>
    StaticDepthView<T>& StaticDepthView<T>::operator=(const Range<T>& r_) noexcept
    {
        size_t rsz=(static_cast<size_t>(r_.end()-r_.begin())/sizeof(T));
        std::memcpy(_ptr, r_.begin(), sizeof(T)*(_depth<rsz ? _depth : rsz));

        return *this;
    }


    template <typename T>
    StaticDepthView<T>& StaticDepthView<T>::operator=(const StaticDepthView<T>& sdv_) noexcept
    {
        std::memcpy(_ptr, sdv_._ptr, sizeof(T)*(_depth<sdv_._depth ? _depth : sdv_._depth));

        return *this;
    }


    template <typename T>
    StaticDepthView<T>& StaticDepthView<T>::operator=(std::initializer_list<T> lst_) noexcept
    {
        std::memcpy(_ptr, lst_.beign(), sizeof(T)*(_depth<lst_.size() ? _depth : lst_.size()));

        return *this;
    }
    


    // Edit Functions
    template <typename T>
    StaticDepthView<T>& StaticDepthView<T>::memset(int ch_) noexcept
    {
        std::memset(_ptr, ch_, sizeof(T)*_depth);
        
        return *this;
    }





    //+++++++++++++++++++++++++++++++++++//
    //    Attached Namespace Function    //
    //+++++++++++++++++++++++++++++++++++//
    template <typename T>
    std::ostream& operator<<(std::ostream& os_, const gd::StaticDepthView<T>& sdv_) noexcept
    {
        if(sdv_.depth()) gd::ostream(sdv_(0), os_);
        for(auto& t : sdv_.range(1, sdv_.depth())){
            os_<<" ";
            gd::ostream(t, os_);
        }
    
        return os_;
    }

}
#endif

/*
#include <complex>
int main(void){
    
    {
        std::cout<<"Alpha"<<std::endl;
        gd::StaticDepthView<double> gr1;
    
        std::cout<<gr1.depth()<<std::endl;
        std::cout<<gr1.size()<<std::endl;
        std::cout<<gr1.capacity()<<std::endl;
    }
    
    {
        std::cout<<"Bravo"<<std::endl;
        gd::StaticDepthView<double> gr1={0, 3, 3, 2, 5};
        gd::StaticDepthView<double> gr2={0, 1};
        gd::StaticDepthView<double> gr3={0, 1, 2, 3, 4, 5, 6};
    
        std::cout<<gr1<<" "<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
        std::cout<<gr2<<" "<<gr2.size()<<" "<<gr2.capacity()<<std::endl;
        std::cout<<gr3<<" "<<gr3.size()<<" "<<gr3.capacity()<<std::endl;
    }
    {
        std::cout<<"Charlie"<<std::endl;
        gd::StaticDepthView<double> gr1={0, 3, 3, 2, 5};
        std::cout<<gr1.ref<0>()<<" "<<gr1.path<0>()<<" "<<gr1.spec()<<" "<<gr1.data()<<std::endl;
        //gr1.ref<0>()[3]=4.5;
        //gr1.ref<2>();
        gr1.path<0>()[3]=4.5;
        //gr1.path<2>();
        //gr1.spec()[3]=4.5;
        gr1.data()[3]=4.2;
        std::cout<<gr1<<std::endl;
    }
    {
        std::cout<<"Delta"<<std::endl;
        gd::StaticDepthView<double> gr1={0, 3, 3, 2, 5};
        std::cout<<gr1(3)<<std::endl;
        //std::cout<<(gr1(3)=2.3)<<std::endl;
        std::cout<<(gr1[3]=2.3)<<std::endl;
        //std::cout<<gr1(5)<<std::endl;
        //std::cout<<(gr1[5]=2.3)<<std::endl;
    }
    {
        std::cout<<"Echo"<<std::endl;
        gd::StaticDepthView<double> gr1={0, 3, 3, 2, 5};
        gr1.destruct(); 
    }
    {
        std::cout<<std::endl<<"Foxtrot"<<std::endl;
        gd::StaticDepthView<double> gr1={0, 3, 3, 2, 5};
        if(!gr1.reserve(100)){
            std::cout<<"Err"<<std::endl;
        }else{
            std::cout<<gr1<<std::endl;
            std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
            gr1.resize(100);
            std::cout<<gr1<<std::endl;
            std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
            gr1.resize(0);
            std::cout<<gr1<<std::endl;
            std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
        }
    }
    {
        std::cout<<std::endl<<"Foxtrot"<<std::endl;
        gd::StaticDepthView<std::complex<double>> gr1(1);
        std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
        gr1.pushBack(std::complex<double>{3, 2});
        std::cout<<gr1<<std::endl;
        std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
        gr1.emplaceBack(2.0, 4.0);
        std::cout<<gr1<<std::endl;
        std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
        gr1.pushBack(std::complex<double>{3, 2});
        gr1.pushBack(std::complex<double>{3, 2});
        gr1.emplaceBack(2.0, 4.0);
        std::cout<<gr1<<std::endl;
        std::cout<<gr1.size()<<" "<<gr1.capacity()<<std::endl;
    }
}
*/
