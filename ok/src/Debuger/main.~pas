unit main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls;

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
    procedure OpenClick(Sender: TObject);
    procedure RefreshClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;

implementation

{$R *.DFM}

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
    n,k: Integer;
    width,heigth,hpos,vpos: Integer;
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
    with MainForm.Canvas do
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
with MainForm.Canvas do
    begin
    Pen.Style:= psSolid;
    Pen.Color:= color;
    Brush.Color:= color;
    Brush.Style:= style;
    end;
for i:= 1 to 2*n do
    task[i].Draw((i+1) div 2,width,hpos,vpos,heigth);
end;

procedure TTasks.DrawIdle(color: TColor; style: TBrushStyle);
var
i: Integer;
begin
with MainForm.Canvas do
    begin
    Pen.Style:= psSolid;
    Pen.Color:= clBlack;
    Pen.Width:= 2;
    Brush.Color:= color;
    Brush.Style:= style;
    for i:= 1 to k do
        with idle[i] do
            begin
            Rectangle(hpos+start*width,vpos,hpos+(start+length)*width,vpos+heigth);
            end;
    end;
end;

procedure TTasks.DrawRuler(color: TColor);
var
i,n: Integer;
begin
with MainForm.Canvas do
    begin
    Pen.Color:= color;
    Pen.Width:= 1;
    Brush.Color:= clWhite;
    n:= (MainForm.ClientWidth-hpos) div width;
    for i:= 0 to n do
        begin
        if (width > 15) or
           ((width > 8) and (i mod 2 = 0)) or
           ((width <= 8) and (width > 6) and (i mod 3 = 0)) or
           ((width <= 6) and (i mod 5 = 0)) then
            TextOut(hpos+i*width-3*Length(IntToStr(i)),vpos+4*heigth+15,IntToStr(i));
        Pen.Style:= psDot;
        MoveTo(hpos+i*width,vpos);
        LineTo(hpos+i*width,vpos+4*heigth);
        Pen.Style:= psSolid;
        LineTo(hpos+i*width,vpos+4*heigth+10);
        LineTo(hpos+(i+1)*width,vpos+4*heigth+10);
        end;
    end;
end;

procedure TMainForm.OpenClick(Sender: TObject);
var
f: TextFile;
i,j,t: Integer;
begin
if OpenDialog.Execute then
    begin
    AssignFile(f, OpenDialog.FileName);
    Reset(f);
    tasks.Free;
    tasks:= TTasks.Create;
    readln(f,tasks.k);
    SetLength(tasks.idle,tasks.k+1);
    for i:= 1 to tasks.k do
        readln(f,tasks.idle[i].start,tasks.idle[i].length);
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
    RefreshClick(Sender);
    end;
end;

procedure TMainForm.RefreshClick(Sender: TObject);
begin
Canvas.Brush.Style:= bsSolid;
Canvas.Brush.Color:= clWhite;
Canvas.FillRect(Rect(0,0,Width,170));

if Assigned(tasks) then
    begin
    tasks.width:= StrToInt(hsize.text);
    tasks.hpos:= StrToInt(hpos.text);
    tasks.vpos:= StrToInt(vpos.text);
    tasks.heigth:= StrToInt(vsize.text);
    tasks.DrawRuler(clGreen);
    tasks.DrawTasks(clBlack, bsDiagCross);
    tasks.DrawIdle(clRed,bsSolid);
    end;
end;
                       
procedure TMainForm.FormCreate(Sender: TObject);
begin
OpenDialog.InitialDir:= GetCurrentDir;
end;

end.
