object MainForm: TMainForm
  Left = 178
  Top = 171
  Width = 588
  Height = 337
  Caption = 'Visual Debuger'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnPaint = RefreshClick
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 200
    Width = 89
    Height = 13
    Caption = 'Horizontal position:'
  end
  object Label2: TLabel
    Left = 16
    Top = 224
    Width = 77
    Height = 13
    Caption = 'Vertical position:'
  end
  object Label3: TLabel
    Left = 16
    Top = 248
    Width = 34
    Height = 13
    Caption = 'Heigth:'
  end
  object Label4: TLabel
    Left = 16
    Top = 272
    Width = 31
    Height = 13
    Caption = 'Width:'
  end
  object Open: TButton
    Left = 248
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 0
    OnClick = OpenClick
  end
  object Refresh: TButton
    Left = 248
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Refresh'
    TabOrder = 1
    OnClick = RefreshClick
  end
  object hpos: TEdit
    Left = 136
    Top = 200
    Width = 41
    Height = 21
    TabOrder = 2
    Text = '20'
    OnExit = RefreshClick
  end
  object vpos: TEdit
    Left = 136
    Top = 224
    Width = 41
    Height = 21
    TabOrder = 3
    Text = '20'
    OnExit = RefreshClick
  end
  object vsize: TEdit
    Left = 136
    Top = 248
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '20'
    OnExit = RefreshClick
  end
  object hsize: TEdit
    Left = 136
    Top = 272
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '20'
    OnExit = RefreshClick
  end
  object OpenDialog: TOpenDialog
    FileName = 'test.txt'
    Filter = 'Pliki tekstowe (*.txt)|*.txt'
    Left = 248
    Top = 264
  end
end
