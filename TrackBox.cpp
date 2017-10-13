#include "TrackBox.h"

TrackBox::TrackBox(uint32_t type, uint32_t size)
    :BaseBox(type, size)
{

}

TrackBox::~TrackBox()
{

}

int TrackBox::Parse(class mp4Parser* parser, uint32_t start_pos)
{
    if(parser->stream_num > MAX_STREAM_COUNT)
    {
        return -1;
    }

    parser->AddStream();

    int index = 0;
    while(index < this->size-8)
    {
        BaseBox* box = parser->ReadBox(start_pos + index);
        parser->AddBox(this, box);
        index += box->size;
        parser->io->SetPos(start_pos + index);
    }
    return 0;
}
