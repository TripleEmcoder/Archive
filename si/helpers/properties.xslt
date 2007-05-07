<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:output method="xml" indent="yes" />
  <xsl:strip-space elements="*" />
  
  <xsl:template match="/">
    <summary>
      <xsl:for-each select="//plant[2]/property">
        <property name="{@name}">
          <xsl:variable name="name" select="@name" />
          <xsl:for-each select="distinct-values(//property[@name=$name]/@value)">
            <xsl:sort select="." />
            <value>
              <xsl:value-of select="." />
            </value>
          </xsl:for-each>
        </property>
      </xsl:for-each>
    </summary>
  </xsl:template>

</xsl:stylesheet>
