# firearrow

Android application for test and measure Java/C++ features.

The purpose of the application is to test, compare and measure time execution</br> 
 Java/C++ simialar functionalities.

![List of features](screenshot/firearrow_1.jpg "A list of features")
![Filesystem feature](screenshot/firearrow_2.jpg "A erase filesystem feature")

Features:
---------
  * filesystem - compare Java vs C++ erase file facilities
  * async      - compare Java vs C++ asyncronously facilities
  * simd       - compare Java vs C++ vector instruction facilities

Architecture:
-------------
MVVM (Model View ViewModel)

Used Android libraries:
-----------------------
  * AppCompat
  * App Startup
  * Lifecycle/LiveData
  * ViewModel
  * Pagging
  * Navigation
  * Room
  * DataStore
  * WorkManager
  
Used third party libraries:
--------------------------
  * Timber
  * Glide
  * Hilt
  * RxJava3
  * Jpml(pattern matching)

Languages:
----------
  * Java 11
  * C++ 20
  
