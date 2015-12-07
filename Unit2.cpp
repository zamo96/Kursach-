//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

struct Day
{
    float TempMorning; // ����������� �����
    float TempDay;     // ����������� ����
    float TempEvening; // ����������� �������
    float TempNight;   // ����������� �����

    float VlagMorning; // ��������� �����
    float VlagDay;     // ��������� ����
    float VlagEvening; // ��������� �������
    float VlagNight;   // ��������� �����

    float BarMorning;  // �������� �����
    float BarDay;      // �������� ����
    float BarEvening;  // �������� �������
    float BarNight;    // �������� �����

    char Time [50]; // ����

    char City [50]; // �����
};

extern struct Day* DataOfWeather;
extern int DataOfWeatherCount; // ���������� ��������� � �������
extern TListBox *ListBox1FromForm1;
extern TComboBox *ComboBox1FromForm1;
extern TListView *ListView1FromForm1;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
     DataOfWeather [DataOfWeatherCount].TempMorning = StrToFloat (Edit1->Text);
     DataOfWeather [DataOfWeatherCount].TempDay = StrToFloat (Edit2->Text);
     DataOfWeather [DataOfWeatherCount].TempEvening = StrToFloat (Edit3->Text);
     DataOfWeather [DataOfWeatherCount].TempNight = StrToFloat (Edit4->Text);

     DataOfWeather [DataOfWeatherCount].VlagMorning = StrToFloat (Edit5->Text);
     DataOfWeather [DataOfWeatherCount].VlagDay = StrToFloat (Edit6->Text);
     DataOfWeather [DataOfWeatherCount].VlagEvening = StrToFloat (Edit7->Text);
     DataOfWeather [DataOfWeatherCount].VlagNight = StrToFloat (Edit8->Text);

     DataOfWeather [DataOfWeatherCount].BarMorning = StrToFloat (Edit9->Text);
     DataOfWeather [DataOfWeatherCount].BarDay = StrToFloat (Edit10->Text);
     DataOfWeather [DataOfWeatherCount].BarEvening = StrToFloat (Edit11->Text);
     DataOfWeather [DataOfWeatherCount].BarNight = StrToFloat (Edit12->Text);

     // ����������� ������
     strcpy (DataOfWeather [DataOfWeatherCount].Time, Edit13->Text.c_str());

     // ����������� ������
     strcpy (DataOfWeather [DataOfWeatherCount].City, Edit14->Text.c_str());

     DataOfWeatherCount++;

     Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
     Form2->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (AddDaysInListBox (ListBox1FromForm1) == 0) // ���� ��������� ������ ���������� ���� � ListBox1
    {
        MessageBox (NULL, "������ ���������� ������ � ListBox!", "������", MB_OK | MB_ICONERROR);
    }

    if (AddCitiesInComboBox (ComboBox1FromForm1) == 0) // ���� ��������� ������ ���������� ������� � ComboBox1
    {
        MessageBox (NULL, "������ ���������� ������ � ComboBox!", "������", MB_OK | MB_ICONERROR);
    }

    if (AddInfoInListView (ListView1FromForm1) == 0) // ���� ��������� ������ ���������� ������ � ListView1
    {
        MessageBox (NULL, "������ ���������� ������ � ListView!", "������", MB_OK | MB_ICONERROR);
    }
}
//---------------------------------------------------------------------------

