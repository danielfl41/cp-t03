#ifndef CORDINATE_H
#define CORDINATE_H
#include "cmath"
class Coordinate
{
private:
    long double _lat;
    long double _lng;
    long double toRadians(const long double degree)
    {
        // cmath library in C++
        // defines the constant
        // M_PI as the value of
        // pi accurate to 1e-30
        long double one_deg = (M_PI) / 180;
        return (one_deg * degree);
    }

public:
    Coordinate(long double lat, long double lng)
    {
        this->_lat = lat;
        this->_lng = lng;
    };
    long double lat()
    {
        return this->_lat;
    }
    long double lng()
    {
        return this->_lng;
    }
    long double distance(Coordinate toCompare)
    {
        // Convert the latitudes
        // and longitudes
        // from degree to radians.
        auto lat1 = this->toRadians(this->_lat);
        auto long1 = this->toRadians(this->_lng);
        auto lat2 = this->toRadians(toCompare.lat());
        auto long2 = this->toRadians(toCompare.lng());

        // Haversine Formula
        long double dlong = long2 - long1;
        long double dlat = lat2 - lat1;

        long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                              pow(sin(dlong / 2), 2);

        ans = 2 * asin(sqrt(ans));

        // Radius of Earth in
        // Kilometers, R = 6371
        // Use R = 3956 for miles
        long double R = 6371e3;

        // Calculate the result
        ans = ans * R;

        return ans;
    }
};
#endif