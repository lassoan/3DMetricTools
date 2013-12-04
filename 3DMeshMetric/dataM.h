#ifndef DATAM_H
#define DATAM_H

// VTK libraries
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkDecimatePro.h>
#include <vtkColorTransferFunction.h>
#include <vtkProperty.h>
#include <vtkTriangleFilter.h>
#include <vtkAbstractArray.h>
#include <vtkCleanPolyData.h>

// QT libraries
#include <QMessageBox>

// OTHER libraries
#include <string>
#include <iostream>
#include <vector>

class dataM
{
    public:
        dataM( std::string Name = "" );

        /* set and get the name of the file
         */
        void setName( std::string Name );
        std::string getName();

        /* set and get the polydata file
         */
        void setPolyData(vtkSmartPointer<vtkPolyData> OldData );
        vtkSmartPointer<vtkPolyData> getPolyData();

        /* get the mapper and actor used to display the polydata
         */
        vtkSmartPointer <vtkPolyDataMapper> getMapper();
        vtkSmartPointer <vtkActor> getActor();

        /* Set and get the different properties of the data
         */
        void setOpacity( double Opacity );
        void setColor( double Red , double Green , double Blue );
        void setType( int Type );

        double getOpacity();
        double getRed();
        double getBlue();
        double getGreen();
        int getType();

        /* set and get the parameters for the distance computation
         */
        void setNameB( std::string NameB );
        void setMinSamplingFrequency(int MinSamplingFrequency );
        void setSamplingStep( double SamplingStep );
        void setSignedDistance( bool SignedDistance );
        void setDisplayError( bool DisplayError );

        std::string getNameB();
        int getMinSamplingFrequency();
        double getSamplingStep();
        bool getSignedDistance();
        bool getDisplayError();

        /* set and get the parameters used to compute the color bar
         */
        void setLut( vtkSmartPointer <vtkColorTransferFunction> Lut );
        void setMin( double Dmin );
        void setMax( double Dmax );
        void setCenter( double Center );
        void setDelta( double Delta );
        void setColorBar( bool ColorBar );

        vtkSmartPointer <vtkColorTransferFunction> getLut();
        double getMin();
        double getMax();
        double getCenter();
        double getDelta();
        bool getColorBar();

        /* Read the file
         * Pass by a cleaner and triangler filter
         * Then connect to the mapper and actor
         */
        void initialization();

        /* Update the actor properties
         * the opacity and color
         */
        void updateActorProperties();

        /* update the type of display
         * surface, triangle and points
         */
        int updateTypeOfDisplay();

        /* Change the polydata input of the mapper
         */
        int changeMapperInput();

        /* change the scalar use to display the color map
         */
        void changeActivScalar();

    private:
        std::string m_Name;
        vtkSmartPointer <vtkPolyData> m_PolyData;
        vtkSmartPointer <vtkPolyDataMapper> m_Mapper;
        vtkSmartPointer <vtkActor> m_Actor;

        double m_Opacity;
        double m_Red;
        double m_Blue;
        double m_Green;
        int m_Type;

        std::string m_NameB;
        int m_MinSamplingFrequency;
        double m_SamplingStep;
        bool m_SignedDistance;
        bool m_DisplayError;

        vtkSmartPointer <vtkColorTransferFunction> m_Lut;
        double m_Dmin;
        double m_Dmax;
        double m_Center;
        double m_Delta;
        bool m_ColorBar;
};

#endif
