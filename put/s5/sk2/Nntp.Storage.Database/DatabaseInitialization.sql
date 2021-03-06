/****** Object:  Table [dbo].[Groups]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [Groups](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](100) NOT NULL,
	[Description] [nvarchar](200) NOT NULL,
 CONSTRAINT [PK_Groups] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
CREATE UNIQUE NONCLUSTERED INDEX [IX_Groups_Name] ON [Groups] 
(
	[Name] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Articles]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [Articles](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ParentID] [int] NULL,
	[MessageID] [nvarchar](200) NOT NULL,
	[Subject] [nvarchar](200) NULL,
	[From] [nvarchar](200) NULL,
	[Date] [datetime] NOT NULL,
	[Bytes] [int] NULL,
	[Lines] [int] NULL,
 CONSTRAINT [PK_Articles] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
CREATE UNIQUE NONCLUSTERED INDEX [IX_Articles_MessageID] ON [Articles] 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Postings]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [Postings](
	[GroupID] [int] NOT NULL,
	[ArticleID] [int] NOT NULL,
 CONSTRAINT [PK_Postings] PRIMARY KEY CLUSTERED 
(
	[GroupID] ASC,
	[ArticleID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ArticleHeaders]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [ArticleHeaders](
	[ArticleID] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Value] [nvarchar](200) NOT NULL,
 CONSTRAINT [PK_ArticleHeaders] PRIMARY KEY CLUSTERED 
(
	[ArticleID] ASC,
	[Name] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ArticleBodies]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [ArticleBodies](
	[ArticleID] [int] NOT NULL,
	[Value] [ntext] NOT NULL,
 CONSTRAINT [PK_ArticleBodies] PRIMARY KEY CLUSTERED 
(
	[ArticleID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  View [dbo].[GroupOverviews]    Script Date: 12/01/2007 14:09:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [GroupOverviews]
AS
SELECT     dbo.Groups.ID, dbo.Groups.Name, dbo.Groups.Description, COUNT(dbo.Postings.ArticleID) AS Count, ISNULL(MIN(dbo.Postings.ArticleID), 0) AS Low, 
                      ISNULL(MAX(dbo.Postings.ArticleID), 0) AS High
FROM         dbo.Groups LEFT OUTER JOIN
                      dbo.Postings ON dbo.Postings.GroupID = dbo.Groups.ID
GROUP BY dbo.Groups.ID, dbo.Groups.Name, dbo.Groups.Description
GO
/****** Object:  ForeignKey [FK_ArticleBodies_Articles]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [ArticleBodies]  WITH CHECK ADD  CONSTRAINT [FK_ArticleBodies_Articles] FOREIGN KEY([ArticleID])
REFERENCES [Articles] ([ID])
GO
ALTER TABLE [ArticleBodies] CHECK CONSTRAINT [FK_ArticleBodies_Articles]
GO
/****** Object:  ForeignKey [FK_ArticleHeaders_Articles]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [ArticleHeaders]  WITH CHECK ADD  CONSTRAINT [FK_ArticleHeaders_Articles] FOREIGN KEY([ArticleID])
REFERENCES [Articles] ([ID])
GO
ALTER TABLE [ArticleHeaders] CHECK CONSTRAINT [FK_ArticleHeaders_Articles]
GO
/****** Object:  ForeignKey [FK_Articles_Articles]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [Articles]  WITH CHECK ADD  CONSTRAINT [FK_Articles_Articles] FOREIGN KEY([ParentID])
REFERENCES [Articles] ([ID])
GO
ALTER TABLE [Articles] CHECK CONSTRAINT [FK_Articles_Articles]
GO
/****** Object:  ForeignKey [FK_Groups_Groups]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [Groups]  WITH CHECK ADD  CONSTRAINT [FK_Groups_Groups] FOREIGN KEY([ID])
REFERENCES [Groups] ([ID])
GO
ALTER TABLE [Groups] CHECK CONSTRAINT [FK_Groups_Groups]
GO
/****** Object:  ForeignKey [FK_Postings_Articles]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [Postings]  WITH CHECK ADD  CONSTRAINT [FK_Postings_Articles] FOREIGN KEY([ArticleID])
REFERENCES [Articles] ([ID])
GO
ALTER TABLE [Postings] CHECK CONSTRAINT [FK_Postings_Articles]
GO
/****** Object:  ForeignKey [FK_Postings_Groups]    Script Date: 12/01/2007 14:09:15 ******/
ALTER TABLE [Postings]  WITH CHECK ADD  CONSTRAINT [FK_Postings_Groups] FOREIGN KEY([GroupID])
REFERENCES [Groups] ([ID])
GO
ALTER TABLE [Postings] CHECK CONSTRAINT [FK_Postings_Groups]
GO
