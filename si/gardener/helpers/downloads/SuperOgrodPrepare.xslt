<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!--<xsl:output method="xml" indent="yes" />-->
  <!--<xsl:strip-space elements="*" />-->

  <xsl:template match="plant">
    <plant>
      <xsl:apply-templates select="*|@*" />
      <xsl:attribute name="name">
        <xsl:value-of select="@name"/>
        <xsl:variable name="name" select="@name" />
        <xsl:variable name="path" select="@path" />
        <xsl:if test="count(//plant[@name=$name]) &gt; 1">
          <xsl:for-each select="//plant[@name=$name]">
            <xsl:if test="@path=$path">
              <xsl:value-of select="concat(' ', position())"/>
            </xsl:if>
          </xsl:for-each>
        </xsl:if>
      </xsl:attribute>
    </plant>
  </xsl:template>

  <xsl:template match="*|@*">
    <xsl:copy>
      <xsl:apply-templates select="*|@*" />
    </xsl:copy>
  </xsl:template>

</xsl:stylesheet>