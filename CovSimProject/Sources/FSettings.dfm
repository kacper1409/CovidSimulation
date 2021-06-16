object FmSettings: TFmSettings
  Left = 0
  Top = 0
  Caption = 'FmSettings'
  ClientHeight = 466
  ClientWidth = 416
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LabelAreaHeight: TLabel
    Left = 130
    Top = 265
    Width = 102
    Height = 13
    Caption = 'Szansa na zara'#380'enie:'
  end
  object LabelBoxLen: TLabel
    Left = 130
    Top = 224
    Width = 77
    Height = 13
    Caption = 'Czas zdrowienia'
  end
  object LabelPopulation: TLabel
    Left = 132
    Top = 24
    Width = 50
    Height = 13
    Caption = 'Populacja:'
  end
  object Label1: TLabel
    Left = 131
    Top = 64
    Width = 98
    Height = 13
    Caption = 'Rozmiar X mapy (kl):'
  end
  object Label2: TLabel
    Left = 131
    Top = 105
    Width = 98
    Height = 13
    Caption = 'Rozmiar Y mapy (kl):'
  end
  object Label3: TLabel
    Left = 130
    Top = 143
    Width = 92
    Height = 13
    Caption = 'Rozmiar klatki (px):'
  end
  object Label4: TLabel
    Left = 130
    Top = 183
    Width = 104
    Height = 13
    Caption = 'Pocz'#261'tkowo zara'#380'eni:'
  end
  object BitBtnOk: TBitBtn
    Left = 112
    Top = 371
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 0
  end
  object BitBtnCancel: TBitBtn
    Left = 208
    Top = 371
    Width = 75
    Height = 25
    Kind = bkCancel
    NumGlyphs = 2
    TabOrder = 1
  end
  object EditAreaWidth: TEdit
    Left = 235
    Top = 61
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 2
  end
  object EditAreaHeight: TEdit
    Left = 235
    Top = 102
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 3
  end
  object EditBoxLen: TEdit
    Left = 235
    Top = 140
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 4
  end
  object EditPopulation: TEdit
    Left = 235
    Top = 21
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 5
  end
  object EditInfectionDuration: TEdit
    Left = 235
    Top = 221
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 6
  end
  object EditRiskOfInfection: TEdit
    Left = 234
    Top = 262
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 7
  end
  object EditInitInfectedPeople: TEdit
    Left = 235
    Top = 180
    Width = 48
    Height = 21
    NumbersOnly = True
    TabOrder = 8
  end
end
