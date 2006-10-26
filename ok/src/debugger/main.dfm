object MainForm: TMainForm
  Left = 218
  Top = 179
  AutoScroll = False
  Caption = 'Visual Debuger'
  ClientHeight = 303
  ClientWidth = 580
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
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
    Left = 232
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 0
    OnClick = OpenClick
  end
  object Refresh: TButton
    Left = 232
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
    Text = '25'
    OnExit = RefreshClick
  end
  object hsize: TEdit
    Left = 136
    Top = 272
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '5'
    OnExit = RefreshClick
  end
  object ScrollBox: TScrollBox
    Left = 0
    Top = 0
    Width = 580
    Height = 185
    HorzScrollBar.Tracking = True
    VertScrollBar.Visible = False
    Align = alTop
    TabOrder = 6
    object Diagram: TImage
      Left = 0
      Top = 0
      Width = 576
      Height = 181
    end
  end
  object DrawTasks: TCheckBox
    Left = 352
    Top = 200
    Width = 97
    Height = 17
    Caption = 'Draw tasks'
    Checked = True
    State = cbChecked
    TabOrder = 7
    OnClick = RefreshClick
  end
  object DrawIdle: TCheckBox
    Left = 352
    Top = 224
    Width = 97
    Height = 17
    Caption = 'Draw offlines'
    Checked = True
    State = cbChecked
    TabOrder = 8
    OnClick = RefreshClick
  end
  object DrawRuler: TCheckBox
    Left = 352
    Top = 248
    Width = 97
    Height = 17
    Caption = 'Draw ruler'
    Checked = True
    State = cbChecked
    TabOrder = 9
    OnClick = RefreshClick
  end
  object Save: TButton
    Left = 232
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 10
    OnClick = SaveClick
  end
  object OpenDialog: TOpenDialog
    FileName = 'test.txt'
    Filter = 'Pliki tekstowe (*.txt)|*.txt'
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Left = 192
    Top = 264
  end
  object SaveDialog: TSavePictureDialog
    Left = 192
    Top = 232
  end
end
