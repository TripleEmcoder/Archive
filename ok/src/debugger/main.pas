unit main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls, ExtDlgs, CheckLst;

type
  TMainForm = class(TForm)
    OpenDialog: TOpenDialog;
    Open: TButton;
    Refresh: TButton;
    hpos: TEdit;
    Label1: TLabel;
    vpos: TEdit;
    Label2: TLabel;
    Label3: TLabel;
    hsize: TEdit;
    Label4: TLabel;
    vsize: TEdit;
    ScrollBox: TScrollBox;
    Diagram: TImage;
    DrawTasks: TCheckBox;
    DrawIdle: TCheckBox;
    DrawRuler: TCheckBox;
    Save: TButton;
    SaveDialog: TSavePictureDialog;
    CheckList: TCheckListBox;
    procedure OpenClick(Sender: TObject);
    procedure RefreshClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure SaveClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;

implementation

{$R *.DFM}

uses
Math;

type
TPart = record
    start,length: Integer;
    end;
TTask = class(Tobject)
    arrival,setup,m: Integer;
    up: Boolean;
    part: array of TPart;
    procedure Draw(nr,width,hpos,vpos,height: Integer);
    end;
TTasks = class(Tobject)
    n,k,cmax: Integer;
    width,height,hpos,vpos: Integer;
    idle: array of TPart;
    task: array of TTask;
    procedure DrawTasks(color: TColor; style: TBrushStyle);
    procedure DrawIdle(color: TColor; style: TBrushStyle);
    procedure DrawRuler(color: TColor);
    end;


var
tasks: TTasks;

procedure TTask.Draw(nr,width,hpos,vpos,height: Integer);
var
i: Integer;
style: TBrushStyle;
color: TColor;
begin
if not up then Inc(vpos,2*height);
for i:= 1 to m do
    with MainForm.Diagram.Picture.Bitmap.Canvas do
        with part[i] do
            begin
            color:= Brush.Color;
            style:= Brush.Style;
            Pen.Color:= clBlack;
            Pen.Style:= psSolid;
            Pen.Width:= 2;
            Brush.Style:= bsSolid;
            Brush.Color:= clWhite;
            Rectangle(hpos+(start-setup)*width,vpos,hpos+(start+length)*width,vpos+height); //ramka
            Pen.Width:= 1;
            Brush.Style:= style;
            Brush.Color:= color;
            Rectangle(hpos+(start-setup)*width,vpos,hpos+(start)*width,vpos+height);
            TextOut(Round(hpos+(start+ length / 2)*width)-2,vpos+4,IntToStr(nr));
            end;
end;

procedure TTasks.DrawTasks(color: TColor; style: TBrushStyle);
var
i: Integer;
begin
with MainForm.Diagram.Picture.Bitmap.Canvas do
    begin
    Pen.Style:= psSolid;
    Pen.Color:= color;
    Brush.Color:= color;
    Brush.Style:= style;
    end;
for i:= 1 to 2*n do
    if MainForm.CheckList.Checked[(i+1) div 2 - 1] then
        task[i].Draw((i+1) div 2,width,hpos,vpos,height);
end;

procedure TTasks.DrawIdle(color: TColor; style: TBrushStyle);
var
i: Integer;
begin
with MainForm.Diagram.Picture.Bitmap.Canvas do
    begin
    Pen.Style:= psSolid;
    Pen.Color:= clBlack;
    Pen.Width:= 2;
    Brush.Color:= color;
    Brush.Style:= style;
    for i:= 1 to k do
        with idle[i] do
            Rectangle(hpos+start*width,vpos,hpos+(start+length)*width,vpos+height);
    end;
end;

procedure TTasks.DrawRuler(color: TColor);
var
i,n,step: Integer;
begin
with MainForm.Diagram.Picture.Bitmap.Canvas do
    begin
    Pen.Color:= color;
    Pen.Width:= 1;
    Brush.Color:= clWhite;
    n:= (MainForm.Diagram.Width-hpos) div width;
    case width of
        1: step:= 25;
        2: step:= 10;
        3: step:= 10;
        4..5: step:= 5;
        6..10: step:= 3;
        11..15: step:= 2;
    else
        step:= 1;
    end;
    i:= 0;
    while (i <= n) do
        begin
        TextOut(hpos+i*width-3*Length(IntToStr(i)),vpos+4*height+15,IntToStr(i));
        Pen.Style:= psDot;
        MoveTo(hpos+i*width,vpos);
        LineTo(hpos+i*width,vpos+4*height);
        Pen.Style:= psSolid;
        LineTo(hpos+i*width,vpos+4*height+10);
        LineTo(hpos+(i+step)*width,vpos+4*height+10);
        Inc(i,step);
        end;
    end;
end;

procedure ReadFromFile(name: string);
var
f: TextFile;
i,j,t: Integer;
begin
    AssignFile(f, name);
    Reset(f);
    tasks.Free;
    tasks:= TTasks.Create;
    readln(f,tasks.k);
    SetLength(tasks.idle,tasks.k+1);
    for i:= 1 to tasks.k do
        read(f,tasks.idle[i].start,tasks.idle[i].length);
    readln(f);
    readln(f,tasks.n);
    SetLength(tasks.task,2*tasks.n+1);
    for i:= 1 to tasks.n do
        with tasks do
            begin
            task[2*i-1].Free;
            task[2*i].Free;
            task[2*i-1]:= TTask.Create;
            task[2*i]:= TTask.Create;
            readln(f,task[2*i-1].arrival,task[2*i-1].setup,t,task[2*i].setup);
            task[2*i].arrival:= task[2*i-1].arrival;
            task[2*i-1].up:= true;
            task[2*i].up:= false;
            end;
    readln(f,tasks.cmax);
    readln(f);
    for i:= 1 to 2*tasks.n do
        with tasks do
            begin
            readln(f,task[i].m);
            SetLength(task[i].part,task[i].m+1);
            for j:= 1 to task[i].m do
                read(f,task[i].part[j].start,task[i].part[j].length);
            readln(f);
            end;
    CloseFile(f);
    with MainForm do
        begin
        CheckList.Items.Clear;
        for i:= 1 to tasks.n do
            begin
            CheckList.Items.Add('Task '+IntToStr(i));
            CheckList.Checked[i-1]:= True;
            end;
        RefreshClick(MainForm);
        end;
end;

procedure TMainForm.OpenClick(Sender: TObject);
begin
if OpenDialog.Execute then
    begin
    ReadFromFile(OpenDialog.Filename);
    end;
end;

procedure TMainForm.RefreshClick(Sender: TObject);
begin
if Assigned(tasks) then
    begin
    tasks.width:= StrToInt(hsize.text);
    tasks.hpos:= StrToInt(hpos.text);
    tasks.vpos:= StrToInt(vpos.text);
    tasks.height:= StrToInt(vsize.text);
    Diagram.Height:= ScrollBox.ClientHeight;
    Diagram.Width:= 2*tasks.hpos+tasks.cmax*tasks.width;
    Diagram.Picture.Bitmap.Height:= Diagram.Height;
    Diagram.Picture.Bitmap.Width:= Diagram.Width;
    with MainForm.Diagram.Picture.Bitmap.Canvas do
        begin
        Brush.Style:= bsSolid;
        Brush.Color:= clWhite;
        FillRect(Rect(0,0,Diagram.Width,Diagram.Height));
        end;
    if DrawRuler.Checked then tasks.DrawRuler(clGreen);
    if DrawTasks.Checked then tasks.DrawTasks(clBlack, bsDiagCross);
    if DrawIdle.Checked then tasks.DrawIdle(clRed,bsSolid);
    end
else
    OpenClick(Sender);
end;
                       
procedure TMainForm.FormCreate(Sender: TObject);
begin
OpenDialog.InitialDir:= GetCurrentDir;
SaveDialog.InitialDir:= GetCurrentDir;
if ParamCount = 1 then
    ReadFromFile(ParamStr(1));
end;

procedure TMainForm.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
if (key = VK_RETURN) then
    RefreshClick(Sender);
end;

procedure TMainForm.SaveClick(Sender: TObject);
begin
if SaveDialog.Execute then
    begin
    Diagram.Picture.SaveToFile(SaveDialog.Filename);
    end;
end;

end.
