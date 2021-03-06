//
//  GoogleMap.h
//  emptyExample
//
//  Created by David Stolarsky on 3/5/13.
//
//

#ifndef __emptyExample__GoogleMap__
#define __emptyExample__GoogleMap__

#include <ofMain.h>

#include "DNS/Geometry.h"

#include <set>

class GoogleMap {
    
public:
    GoogleMap() {};
    void load(int zoomLevel, Bounds<float> latLngBounds);
    
    void setLatLngBounds(const Bounds<float> & bounds);
    void setScreenBounds(Bounds<float> screenBounds);
    
    Bounds<float> getLatLngBounds() { return latLngBounds; };
    
    void draw(float x, float y);
    
    //Bounds<float> latLngToNormalizedGoogleWorld(const Bounds<float> & latLngBounds) const;
    //ofVec2f googleMercator(float lat, float lng) const;
    
    ofImage map;
    
private:
    class TileLocator
    {
    public:
        ofVec2f center;
        unsigned short zoomLevel;
        
        string filename()
        {
            stringstream f;
            f << "google_staticmap_" << center.x << "_" << center.y << "_" << zoomLevel << ".png";
            return f.str();
        };
    };
    
    void update();
    //void ensureVisibleTiles();
    //void ensureTile(int zoomLevel, int x, int y);
    string tileKey(int zoomLevel, int x, int y);
    string tileLatLngCenterStr(int zoomLevel, int x, int y);
    ofVec2f tile2LatLng(int zoomLevel, float x, float y);
    Bounds<int> getTileBounds();
    
    //int zoomLevel() { return floor(zoom); }
    //int tileSize() { return 1 << zoomLevel(); }
    
    Bounds<float> latLngBounds;
    
    Bounds<float> screenBounds;
    
    Bounds<float> normalizedWorldBounds;
    float zoom;
    ofImage tile;
    //map< string, ofImage > tiles;
    bool loaded = false;
    
    // new strategy
    
    int zoomLevel;
    
    
    void setGoogleZoomLevel(unsigned char zoomLevel) { this->zoomLevel = zoomLevel; };
    ofImage makeMap();
    ofImage loadTileFromGoogleCached(TileLocator tileLocator);
    
    Bounds<float> latLngToGooglePixel(const Bounds<float> & latLngBounds) const;
    ofVec2f latLngToGooglePixel(ofVec2f latLng) const;
    ofVec2f googlePixelToNormalizedGoogleWorld(ofVec2f googlePixel) const;
    ofVec2f googlePixelToLatLng(ofVec2f googlePixel) const;
    ofVec2f googleMercator(ofVec2f latLng) const;
};

#endif /* defined(__emptyExample__GoogleMap__) */
