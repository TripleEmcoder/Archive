<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:str2="http://gotdotnet.com/exslt/strings">

  <!--<xsl:output method="xml" indent="yes" />-->
  <!--<xsl:strip-space elements="*" />-->
  
  <xsl:template match="/">
    <plant>
      <xsl:apply-templates select="//span[@id='op']" />
      <xsl:apply-templates select="//img[contains(@src, 'encfoto')]" />
    </plant>
  </xsl:template>

  <xsl:template match="span">
    <property name="{str2:lowercase(.)}" value="{normalize-space(following::text())}" />
  </xsl:template>

  <xsl:template match="img">
    <photo path="{@src}" />
  </xsl:template>
</xsl:stylesheet>