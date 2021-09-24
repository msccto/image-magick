{
  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Pixel Iterator Methods.
}

type
 VirtualPixelMethod = (
  UndefinedVirtualPixelMethod,
  BackgroundVirtualPixelMethod,
  ConstantVirtualPixelMethod,  // deprecated */
  DitherVirtualPixelMethod,
  EdgeVirtualPixelMethod,
  MirrorVirtualPixelMethod,
  RandomVirtualPixelMethod,
  TileVirtualPixelMethod,
  TransparentVirtualPixelMethod,
  MaskVirtualPixelMethod,
  BlackVirtualPixelMethod,
  GrayVirtualPixelMethod,
  WhiteVirtualPixelMethod,
  HorizontalTileVirtualPixelMethod,
  VerticalTileVirtualPixelMethod,
  HorizontalTileEdgeVirtualPixelMethod,
  VerticalTileEdgeVirtualPixelMethod,
  CheckerTileVirtualPixelMethod
 );

type
  PNexusInfo = ^NexusInfo;
  PPNexusInfo = ^PNexusInfo;

  NexusInfo = record
    mapped: MagickBooleanType;
    region: RectangleInfo;
    length: MagickSizeType;
    cache, pixels: PPixelPacket;
    authentic_pixel_cache: MagickBooleanType;
    indexes: ^Quantum;
    signature: culong;
    virtual_nexus: PNexusInfo;
  end;

type
  CacheView = record
    image: PImage;
    virtual_pixel_method: VirtualPixelMethod;
    number_threads: culong;
    nexus_info: PPNexusInfo;
    debug: MagickBooleanType;
    signature: culong;
  end;

  PCacheView = ^CacheView;

type
  PixelIterator = record
    id: culong;

    name: array[0..MaxTextExtent] of AnsiChar;

    exception: PExceptionInfo;

    view: PCacheView;

    region: RectangleInfo;

    active: MagickBooleanType;

    y: cint;

    pixel_wand: PPPixelWand;

    debug: MagickBooleanType;

    signature: culong;
  end;
  
  PPixelIterator = ^PixelIterator;

var
PixelGetIteratorException: function(const iterator: PPixeliterator;
 severity: PExceptionType): PAnsiChar; cdecl;

IsPixelIterator: function(const iterator: PPixeliterator): MagickBooleanType; cdecl;
PixelClearIteratorException: function(iterator: PPixeliterator): MagickBooleanType; cdecl;
PixelSetIteratorRow: function(iterator: PPixeliterator;
 const row: cint): MagickBooleanType; cdecl;
PixelSyncIterator: function(iterator: PPixeliterator): MagickBooleanType; cdecl;

DestroyPixelIterator: function(iterator: PPixeliterator): PPixelIterator; cdecl;
NewPixelIterator: function(wand: PMagickWand): PPixelIterator; cdecl;
NewPixelRegionIterator: function(
 wand: PMagickWand; const x, y: cint; const columns, rows: culong;
 const modify: MagickBooleanType): PPixelIterator; cdecl;

PixelGetNextIteratorRow: function(iterator: PPixeliterator; var wandCount: culong): PPPixelWand; cdecl;
PixelGetPreviousIteratorRow: function(iterator: PPixeliterator; var wandCount: culong): PPPixelWand; cdecl;

ClearPixelIterator: procedure(iterator: PPixeliterator); cdecl;
PixelResetIterator: procedure(iterator: PPixeliterator); cdecl;
PixelSetFirstIteratorRow: procedure(iterator: PPixeliterator); cdecl;
PixelSetLastIteratorRow: procedure(iterator: PPixeliterator); cdecl;

{
  Deprecated.
}
{extern WandExport char
  *PixelIteratorGetException(const PixelIterator *,ExceptionType *);

extern WandExport PixelWand
  **PixelGetNextRow(PixelIterator *);}

