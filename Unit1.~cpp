//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>  // Заголовочный файл с функциями для чтения данных из файла
#include <stdlib.h> // Заголовочный файл с функциями для выделения и освобождения памяти
#include <string.h> // Заголовочный файл с функциями для работы со строками
#include <iostream>
#pragma hdrstop


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;


struct Day
{
    float TempMorning; // Температура утром
    float TempDay;     // Температура днем
    float TempEvening; // Температура вечером
    float TempNight;   // Температура ночью

    float VlagMorning; // Влажность утром
    float VlagDay;     // Влажность днем
    float VlagEvening; // Влажность вечером
    float VlagNight;   // Влажность ночью

    float BarMorning;  // Давление утром
    float BarDay;      // Давление днем
    float BarEvening;  // Давление вечером
    float BarNight;    // Давление ночью    

    char Time [50]; // Дата

    char City [50]; // Город
};

struct Day* DataOfWeather = NULL; // Изначально память для массива не выделена
int DataOfWeatherCount; // Количество элементов в массиве
AnsiString FileName; // Имя файла


int ReadDataFromFile (AnsiString FileName, char* City)
{
    FILE* File;       // Переменная для открытия файла и чтения данных из него
    char Str [500];   // Переменная, в которую читается каждая строка из файла
    int i;            // Номер элемента Day в массиве для обрабатываемой строки 
    char* StrPos;     // Позиция запятой в строке
    char* StrStart;   // Начало значения в строке


    if (DataOfWeather != NULL) free (DataOfWeather);

    File = fopen (FileName.c_str(), "r"); // fopen - функция которая открывает файл
                                          // c_str() - фукнция, возвращающая имя файла как указатель на char, для функции fopen
                                          // "r" - режим работы с файлом, только чтение
    if (File == NULL) return 0; // Если файл не был открыт, возвращается 0 (ошибка)

    DataOfWeatherCount = 0; // Заранее количество строк неизвестно, поэтому переменная DataOfWeatherCount равна 0 

    // Подсчет количества строк с данными в файле
    while (feof (File) == 0) // feof - функция, которая возвращает ненулевое значение, если достигнут конец файла
    {
        if (fgets (Str, sizeof (Str), File) != NULL) // Если строка была успешно прочитана
        {
            if (strlen (Str) > 0 && Str [0] != ';') DataOfWeatherCount++; // Если длина строки больше нуля и начинается не с ; то увеличиваем количество строк с данными
        }
    }

    DataOfWeather = (struct Day*) malloc ((DataOfWeatherCount + 1000) * sizeof (Day)); // Выделение памяти в в размере: (количество строк + 1000 для добавляемых вручную данных) * размер струкруры Day
    if (DataOfWeather == NULL) // Если память не была выделена
    {
        fclose (File); // Закрытие файла

        return 0; // Возврат 0 (ошибка)
    }

    memset (DataOfWeather, 0, DataOfWeatherCount * sizeof (Day)); // Заполнение выделенной памяти нулями

    rewind (File); // Возврат в начало файла

    i = 0; // Отсчет элемементов в массиве начинается с 0

    while (feof (File) == 0)
    {
        if (fgets (Str, sizeof (Str), File) != NULL) // Если строка была успешно прочитана
        {
            if (strlen (Str) > 0 && Str [0] != ';') // Если длина строки больше нуля и начинается не с ; то увеличиваем количество строк с данными
            {
                // Выделение из строки частей, разделенных запятой
                StrStart = Str;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].TempMorning = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].TempDay = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].TempEvening = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].TempNight = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].VlagMorning = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].VlagDay = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].VlagEvening = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].VlagNight = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].BarMorning = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].BarDay = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].BarEvening = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    DataOfWeather [i].BarNight = StrToFloat (StrStart); // Переводим значение в виде строки в значение тип float и заносим в переменную в структуре
                }

                StrStart = StrPos + 1;
                StrPos = strchr (StrStart, ','); // Поиск запятой в строке
                if (StrPos != NULL) // Если запятая найдена
                {
                    *StrPos = 0; // Запятая заменяется на 0 (конец строки)

                    strncpy (DataOfWeather [i].Time, StrStart, sizeof (DataOfWeather [i].Time) - 1); // Копируем выделенную строку в DataOfWeather [i].Time, оставляя место для 0 в конце строки (sizeof (DataOfWeather [i].Time) - 1);
                }

                StrStart = StrPos + 1;
                strncpy (DataOfWeather [i].City, StrStart, sizeof (DataOfWeather [i].City) - 1); // Копируем выделенную строку в DataOfWeather [i].City, оставляя место для 0 в конце строки (sizeof (DataOfWeather [i].City) - 1);

                // Убираем символ перевода строки после названия города
                if (DataOfWeather [i].City [strlen (DataOfWeather [i].City) - 1] == '\n') DataOfWeather [i].City [strlen (DataOfWeather [i].City) - 1] = 0;

/*
                MessageBoxA(0,FloatToStr (DataOfWeather [i].TempMorning).c_str(),"TempMorning",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].TempDay).c_str(),"TempDay",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].TempEvening).c_str(),"TempEvening",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].TempNight).c_str(),"TempNight",MB_OK);

                MessageBoxA(0,FloatToStr (DataOfWeather [i].VlagMorning).c_str(),"VlagMorning",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].VlagDay).c_str(),"VlagDay",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].VlagEvening).c_str(),"VlagEvening",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].VlagNight).c_str(),"VlagNight",MB_OK);

                MessageBoxA(0,FloatToStr (DataOfWeather [i].BarMorning).c_str(),"BarMorning",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].BarDay).c_str(),"BarDay",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].BarEvening).c_str(),"BarEvening",MB_OK);
                MessageBoxA(0,FloatToStr (DataOfWeather [i].BarNight).c_str(),"BarNight",MB_OK);

                MessageBoxA(0,DataOfWeather [i].Time,"Time",MB_OK);

                MessageBoxA(0,DataOfWeather [i].City,"City",MB_OK);
*/
                if (City == NULL || strcmp (DataOfWeather [i].City, City) == 0) i++;

            }
        }
    }

    DataOfWeatherCount = i;

    fclose (File); // Закрытие файла

    return 1;
}


int AddDaysInListBox (TListBox* ListBox)
{
    ListBox->Clear(); // Удаление всех данных из ListBox, если они там есть

    if (DataOfWeather == NULL) return 0; // Если память для массива не выделена, возвращается 0 (ошибка)

    if (DataOfWeatherCount == 0) return 0; // Если количество элементов в массиве равно 0, возвращается 0 (ошибка)

    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {
        ListBox->AddItem (DataOfWeather [i].Time, NULL); // Добавление строки со временем в ListBox
    }

    return 1;
}

int AddCitiesInComboBox (TComboBox* ComboBox)
{
    bool       CityAdded; // Город уже добавлен в список
    AnsiString City;      // Выбранное значение города в списке


    if (DataOfWeather == NULL) return 0; // Если память для массива не выделена, возвращается 0 (ошибка)

    if (DataOfWeatherCount == 0) return 0; // Если количество элементов в массиве равно 0, возвращается 0 (ошибка)

    ComboBox->Clear();

    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {
        CityAdded = false;
    
        for (int j = 0; j < ComboBox->Items->Count; j++)
        {
            City = ComboBox->Items->Strings [j];

            if (SameText (City, AnsiString (DataOfWeather [i].City)) == True)
            {
                CityAdded = true;

                break;
            }
        }

        if (CityAdded == false && City != NULL)
        {
            ComboBox->Items->Add (AnsiString (DataOfWeather [i].City));
        }
    }

    ComboBox->Sorted = True;

    return 1;
}


int AddInfoInListView (TListView* ListView)
{
    if (DataOfWeather == NULL) return 0; // Если память для массива не выделена, возвращается 0 (ошибка)

    if (DataOfWeatherCount == 0) return 0; // Если количество элементов в массиве равно 0, возвращается 0 (ошибка)

    ListView->Clear();

    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {
        ListView->Items->Add ();
        TListItem* TableLine = ListView->Items->Item [ListView->Items->Count - 1]; // Новая строка

        TableLine->Caption = AnsiString (DataOfWeather [i].Time);

        TableLine->SubItems->Add(DataOfWeather [i].TempMorning);
        TableLine->SubItems->Add(DataOfWeather [i].TempDay);
        TableLine->SubItems->Add(DataOfWeather [i].TempEvening);
        TableLine->SubItems->Add(DataOfWeather [i].TempNight);

        TableLine->SubItems->Add(DataOfWeather [i].VlagMorning);
        TableLine->SubItems->Add(DataOfWeather [i].VlagDay);
        TableLine->SubItems->Add(DataOfWeather [i].VlagEvening);
        TableLine->SubItems->Add(DataOfWeather [i].VlagNight);

        TableLine->SubItems->Add(DataOfWeather [i].BarMorning);
        TableLine->SubItems->Add(DataOfWeather [i].BarDay);
        TableLine->SubItems->Add(DataOfWeather [i].BarEvening);
        TableLine->SubItems->Add(DataOfWeather [i].BarNight);
    }

    return 1;
}


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    OpenDialog1->Execute();
    FileName = OpenDialog1->FileName;

    if (ReadDataFromFile (FileName, NULL) == 0) // Если произошла ошибка чтения из файла
    {
        MessageBox (NULL, "Ошибка чтения из файла!", "Ошибка", MB_OK | MB_ICONERROR);

        return;
    }

    if (AddDaysInListBox (ListBox1) == 0) // Если произошла ошибка добавления дней в ListBox1
    {
        MessageBox (NULL, "Ошибка добавления данных в ListBox!", "Ошибка", MB_OK | MB_ICONERROR);
    }

    if (AddCitiesInComboBox (ComboBox1) == 0) // Если произошла ошибка добавления городов в ComboBox1
    {
        MessageBox (NULL, "Ошибка добавления данных в ComboBox!", "Ошибка", MB_OK | MB_ICONERROR);
    }

    if (AddInfoInListView (ListView1) == 0) // Если произошла ошибка добавления данных в ListView1
    {
        MessageBox (NULL, "Ошибка добавления данных в ListView!", "Ошибка", MB_OK | MB_ICONERROR);
    }

    return;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if (ListBox1->Count == 0) // Если данные не загружены, то выводится сообщение
    {
        MessageBox (NULL, "Данные не загружены!", "Информация", MB_OK);

        return;
    }

    if (ListBox1->ItemIndex == -1) // Если дата не выбрана, то выводится сообщение
    {
        MessageBox (NULL, "Дата не выбрана!", "Информация", MB_OK);

        return;
    }

    int SelectedItem = ListBox1->ItemIndex; // Номер выбранной даты (отсчет начинается с нуля)

    float MiddleTemp = (DataOfWeather [SelectedItem].TempMorning + DataOfWeather [SelectedItem].TempDay + DataOfWeather [SelectedItem].TempEvening + DataOfWeather [SelectedItem].TempNight) / 4; // Средняя температура

    float MinTemp = 273; // Минимальная температура;
    float MaxTemp = -273; // Максимальная температура;

    if (DataOfWeather [SelectedItem].TempMorning > MaxTemp) MaxTemp = DataOfWeather [SelectedItem].TempMorning;      // Если теиература утром больше чем -273, то она становится максимальной
    if (DataOfWeather [SelectedItem].TempDay > MaxTemp) MaxTemp = DataOfWeather [SelectedItem].TempDay;              // Если теиература днем больше чем утром, то она становится максимальной
    if (DataOfWeather [SelectedItem].TempEvening > MaxTemp) MaxTemp = DataOfWeather [SelectedItem].TempEvening;      // Если теиература вечером больше чем днём, то она становится максимальной
    if (DataOfWeather [SelectedItem].TempNight > MaxTemp) MaxTemp = DataOfWeather [SelectedItem].TempNight;          // Если температура ночью больше чем вечером, то она становится максимальной

    if (DataOfWeather [SelectedItem].TempMorning < MinTemp) MinTemp = DataOfWeather [SelectedItem].TempMorning;
    if (DataOfWeather [SelectedItem].TempDay < MinTemp) MinTemp = DataOfWeather [SelectedItem].TempDay;
    if (DataOfWeather [SelectedItem].TempEvening < MinTemp) MinTemp = DataOfWeather [SelectedItem].TempEvening;
    if (DataOfWeather [SelectedItem].TempNight < MinTemp) MinTemp = DataOfWeather [SelectedItem].TempNight;

    //MessageBox (NULL, FloatToStr (MinTemp).c_str(), "Минимальное значение", MB_OK);

    Label29->Caption = FloatToStr (MiddleTemp); // Отображение средней температуры
    Label30->Caption = FloatToStr (MinTemp); // Отображение минимальной температуры
    Label31->Caption = FloatToStr (MaxTemp); // Отображение максимальной температуры

    return; // Выход из функции
}

//---------------------------------------------------------------------------



void __fastcall TForm1::ListBox1Click(TObject *Sender) // Функция обрабатывающая двойной клик на дате
{
    TListBox* ListBox = (TListBox*) Sender; // Получаем ListBox - объект, с которым связана функция обработки двойного клика

    int SelectedItem = ListBox->ItemIndex; // Номер выбранной даты (отсчет начинается с нуля)

    Label6->Caption = FloatToStr (DataOfWeather [SelectedItem].TempMorning); // Отображаем температуру утром в Label6, FloatToStr - перевод переменной типа float в строку
    Label7->Caption = FloatToStr (DataOfWeather [SelectedItem].TempDay); // Отображаем температуру днем в Label7, FloatToStr - перевод переменной типа float в строку
    Label8->Caption = FloatToStr (DataOfWeather [SelectedItem].TempEvening); // Отображаем температуру вечером в Label8, FloatToStr - перевод переменной типа float в строку
    Label9->Caption = FloatToStr (DataOfWeather [SelectedItem].TempNight); // Отображаем температуру ночью в Label9, FloatToStr - перевод переменной типа float в строку

    Label14->Caption = FloatToStr (DataOfWeather [SelectedItem].VlagMorning); // Отображаем влажность утром в Label14, FloatToStr - перевод переменной типа float в строку
    Label15->Caption = FloatToStr (DataOfWeather [SelectedItem].VlagDay); // Отображаем влажность днем в Label15, FloatToStr - перевод переменной типа float в строку
    Label16->Caption = FloatToStr (DataOfWeather [SelectedItem].VlagEvening); // Отображаем влажность вечером в Label16, FloatToStr - перевод переменной типа float в строку
    Label17->Caption = FloatToStr (DataOfWeather [SelectedItem].VlagNight); // Отображаем влажность ночью в Label17, FloatToStr - перевод переменной типа float в строку

    Label22->Caption = FloatToStr (DataOfWeather [SelectedItem].BarMorning); // Отображаем давление утром в Label22, FloatToStr - перевод переменной типа float в строку
    Label23->Caption = FloatToStr (DataOfWeather [SelectedItem].BarDay); // Отображаем давление днем в Label23, FloatToStr - перевод переменной типа float в строку
    Label24->Caption = FloatToStr (DataOfWeather [SelectedItem].BarEvening); // Отображаем давление вечером в Label24, FloatToStr - перевод переменной типа float в строку
    Label25->Caption = FloatToStr (DataOfWeather [SelectedItem].BarNight); // Отображаем давление ночью в Label25, FloatToStr - перевод переменной типа float в строку        

    return;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    AnsiString CurrentCity; // Выбранный город


    TComboBox* ComboBox = (TComboBox*) Sender; // Получаем ComboBox - объект, с которым связана функция обработки выбора города

    CurrentCity = ComboBox->Items->Strings [ComboBox->ItemIndex];


    ListView1->Clear();

    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {
        if (SameText (CurrentCity, AnsiString (DataOfWeather [i].City)) == False) continue;

        ListView1->Items->Add ();
        TListItem* TableLine = ListView1->Items->Item [ListView1->Items->Count - 1]; // Новая строка

        TableLine->Caption = AnsiString (DataOfWeather [i].Time);

        TableLine->SubItems->Add(DataOfWeather [i].TempMorning);
        TableLine->SubItems->Add(DataOfWeather [i].TempDay);
        TableLine->SubItems->Add(DataOfWeather [i].TempEvening);
        TableLine->SubItems->Add(DataOfWeather [i].TempNight);

        TableLine->SubItems->Add(DataOfWeather [i].VlagMorning);
        TableLine->SubItems->Add(DataOfWeather [i].VlagDay);
        TableLine->SubItems->Add(DataOfWeather [i].VlagEvening);
        TableLine->SubItems->Add(DataOfWeather [i].VlagNight);

        TableLine->SubItems->Add(DataOfWeather [i].BarMorning);
        TableLine->SubItems->Add(DataOfWeather [i].BarDay);
        TableLine->SubItems->Add(DataOfWeather [i].BarEvening);
        TableLine->SubItems->Add(DataOfWeather [i].BarNight);
    }

    return;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
    ListBox1FromForm1 = Form1->ListBox1;
    ComboBox1FromForm1 = Form1->ComboBox1;
    ListView1FromForm1 = Form1->ListView1;

    if (DataOfWeather == NULL) // Если память для массива не выделена, форма не показывается
    {
        MessageBox (NULL, "Данные не загружены!", "Информация", MB_OK);

        return;
    }

    if (DataOfWeatherCount == 0) // Если количество элементов в массиве равно 0, форма не показывается
    {
        MessageBox (NULL, "Данные не загружены!", "Информация", MB_OK);

        return;
    }

    Form2->Visible = True;

    return;
}
//---------------------------------------------------------------------------

void sort(bool criterie)            // функция сортировки с критерием bool по возрастанию или убыванию
{
 for (int i = 0; i <DataOfWeatherCount;i++)    // создается цикл перебора элементов массива
 {
  for (int j = i;j<DataOfWeatherCount;j++)       // тоже перебераем массив что бы было с чем сравнивать первые элементы с последующими
  {
  if (criterie)                                    // если критерий выбран по возрастанию
  {
   if(DataOfWeather[i].TempMorning > DataOfWeather[j].TempMorning)   // если утренняя температура первого элемента массива структур больше температуры второго элемента массива
   swap(DataOfWeather[i],DataOfWeather[j]);           // меняем местами элементы массива
   }
   else                                                                // если критерий по убыванию
     {
   if(DataOfWeather[i].TempMorning < DataOfWeather[j].TempMorning)         // тоже самое только если меньше
   swap(DataOfWeather[i],DataOfWeather[j]);
   }
  }
 }
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   ListView1->Clear();
     sort(1);       // применяем функцию сортировки sort(1)  1- критерий по возрастанию , 0 по убыванию
    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {

        ListView1->Items->Add ();
        TListItem* TableLine = ListView1->Items->Item [ListView1->Items->Count - 1]; // Новая строка

        TableLine->Caption = AnsiString (DataOfWeather [i].Time);

        TableLine->SubItems->Add(DataOfWeather [i].TempMorning);
        TableLine->SubItems->Add(DataOfWeather [i].TempDay);
        TableLine->SubItems->Add(DataOfWeather [i].TempEvening);
        TableLine->SubItems->Add(DataOfWeather [i].TempNight);

        TableLine->SubItems->Add(DataOfWeather [i].VlagMorning);
        TableLine->SubItems->Add(DataOfWeather [i].VlagDay);
        TableLine->SubItems->Add(DataOfWeather [i].VlagEvening);
        TableLine->SubItems->Add(DataOfWeather [i].VlagNight);

        TableLine->SubItems->Add(DataOfWeather [i].BarMorning);
        TableLine->SubItems->Add(DataOfWeather [i].BarDay);
        TableLine->SubItems->Add(DataOfWeather [i].BarEvening);
        TableLine->SubItems->Add(DataOfWeather [i].BarNight);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
AnsiString Critetie; // Выбранный критерий

   // TComboBox* ComboBox = (TComboBox*) Sender; // Получаем ComboBox - объект, с которым связана функция обработки выбора критерия

    Critetie = ComboBox2->Items->Strings [ComboBox2->ItemIndex];
   if (SameText(Critetie,"по возрастанию"))
   {
    ListView1->Clear();
    sort(1)      ;
     for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {

        ListView1->Items->Add ();
        TListItem* TableLine = ListView1->Items->Item [ListView1->Items->Count - 1]; // Новая строка

        TableLine->Caption = AnsiString (DataOfWeather [i].Time);

        TableLine->SubItems->Add(DataOfWeather [i].TempMorning);
        TableLine->SubItems->Add(DataOfWeather [i].TempDay);
        TableLine->SubItems->Add(DataOfWeather [i].TempEvening);
        TableLine->SubItems->Add(DataOfWeather [i].TempNight);

        TableLine->SubItems->Add(DataOfWeather [i].VlagMorning);
        TableLine->SubItems->Add(DataOfWeather [i].VlagDay);
        TableLine->SubItems->Add(DataOfWeather [i].VlagEvening);
        TableLine->SubItems->Add(DataOfWeather [i].VlagNight);

        TableLine->SubItems->Add(DataOfWeather [i].BarMorning);
        TableLine->SubItems->Add(DataOfWeather [i].BarDay);
        TableLine->SubItems->Add(DataOfWeather [i].BarEvening);
        TableLine->SubItems->Add(DataOfWeather [i].BarNight);
    }
   }
   else
   {
    ListView1->Clear();
   sort(0);
    for (int i = 0; i < DataOfWeatherCount; i++) // В цикле обходятся все элементы массива
    {

        ListView1->Items->Add ();
        TListItem* TableLine = ListView1->Items->Item [ListView1->Items->Count - 1]; // Новая строка

        TableLine->Caption = AnsiString (DataOfWeather [i].Time);

        TableLine->SubItems->Add(DataOfWeather [i].TempMorning);
        TableLine->SubItems->Add(DataOfWeather [i].TempDay);
        TableLine->SubItems->Add(DataOfWeather [i].TempEvening);
        TableLine->SubItems->Add(DataOfWeather [i].TempNight);

        TableLine->SubItems->Add(DataOfWeather [i].VlagMorning);
        TableLine->SubItems->Add(DataOfWeather [i].VlagDay);
        TableLine->SubItems->Add(DataOfWeather [i].VlagEvening);
        TableLine->SubItems->Add(DataOfWeather [i].VlagNight);

        TableLine->SubItems->Add(DataOfWeather [i].BarMorning);
        TableLine->SubItems->Add(DataOfWeather [i].BarDay);
        TableLine->SubItems->Add(DataOfWeather [i].BarEvening);
        TableLine->SubItems->Add(DataOfWeather [i].BarNight);
    }
   }
}
//---------------------------------------------------------------------------

