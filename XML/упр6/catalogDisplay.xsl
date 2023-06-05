<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
   <xsl:template match="/">
      <html>
         <body>
            <h2>My CD Collection</h2>
            <ul>
                  <xsl:for-each select="/track">
                     <xsl:if test="@length='4:04'">
                        <li><xsl:value-of select="text()"/></li>
                     <xsl:if />
                  </xsl:for-each>
            </ul>
            </xsl:for-each>
         </body>
      </html>
   </xsl:template>
</xsl:stylesheet>