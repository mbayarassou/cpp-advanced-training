#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Device
{
    public:
        Device(std::string const model, int systemID, bool isConnected = false, const char* metaData = NULL)
        {
            m_model = model;
            m_systemID = systemID;
            m_isConnected = isConnected;
            // Create m_metaData from metaData
            m_metaDataSize = strlen(metaData);
            m_metaData = new char[m_metaDataSize + 1];
            strcpy(m_metaData, metaData);
        }
        
        Device& operator=(const Device& device)
        {
            // check for self assignment
            if (this != & device) 
            {
                m_model = device.m_model;
                m_systemID = device.m_systemID;
                m_isConnected = device.m_isConnected;
                // Since this is an already existing object we must deallocate existing memory
                delete[] m_metaData;
                // Create m_metaData from metaData
                m_metaDataSize = strlen(device.m_metaData);
                m_metaData = new char[m_metaDataSize + 1];
                strcpy(m_metaData, device.m_metaData);
            }
            return *this;
        }

        std::string getModel()
        {
            return m_model;
        }

        int getSystemID()
        {
            return m_systemID;
        }

        bool getConnStatus()
        {
            return m_isConnected;
        }

        const char* getMetaData()
        {
            return m_metaData;
        }

        void setModel(std::string const model) { m_model = model; }
        void setSystemID(int systemID) { m_systemID = systemID; }
        void setConnStatus(bool isConnected) { m_isConnected = isConnected; }
        void setMetaData(const char* metaData)
        {
            if(m_metaData){
                delete[] m_metaData;
            }
            // Create m_metaData from metaData
            m_metaDataSize = strlen(metaData);
            m_metaData = new char[m_metaDataSize + 1];
            strcpy(m_metaData, metaData);
        }

        void printDevice(Device device)
        {
            std::cout << "Device model: " << device.getModel() << "\n";
        }


        ~Device()
        {
            std::cout << "Device Destructor called." << "\n";
            delete[] m_metaData;
        }

    protected:
        std::string m_model;
    private:    
        int m_systemID = 0;
        bool m_isConnected = false;
        int m_metaDataSize;
        char* m_metaData;
};

int main()
{
    Device myDevice1("INTR-202245", 0x245, false, "f651270d6011098375db09912b03e5e7");
    Device myDevice2("INTR-202245", 0x245, false, "f651270d6011098375db09912b03e4f8");

    std::cout << "Device 1 Model: " << myDevice1.getModel() << "\n";
    std::cout << "Device 1 System ID: " << myDevice1.getSystemID() << "\n";
    std::cout << "Device 1 is connected: " << myDevice1.getConnStatus() << "\n";
    std::cout << "Device 1 meta data: " << myDevice1.getMetaData() << "\n";

    std::cout << "Device 2 Model: " << myDevice2.getModel() << "\n";
    std::cout << "Device 2 System ID: " << myDevice2.getSystemID() << "\n";
    std::cout << "Device 2 is connected: " << myDevice2.getConnStatus() << "\n";
    std::cout << "Device 2 meta data: " << myDevice2.getMetaData() << "\n";

    myDevice2 = myDevice1;
    myDevice1.setMetaData("f651270d6011098375db09912b03e478");
    
    std::cout << "Device 1 Model: " << myDevice1.getModel() << "\n";
    std::cout << "Device 1 System ID: " << myDevice1.getSystemID() << "\n";
    std::cout << "Device 1 is connected: " << myDevice1.getConnStatus() << "\n";
    std::cout << "Device 1 meta data: " << myDevice1.getMetaData() << "\n";

    std::cout << "Device 2 Model: " << myDevice2.getModel() << "\n";
    std::cout << "Device 2 System ID: " << myDevice2.getSystemID() << "\n";
    std::cout << "Device 2 is connected: " << myDevice2.getConnStatus() << "\n";
    std::cout << "Device 2 meta data: " << myDevice2.getMetaData() << "\n";
}